/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprevrha <aprevrha@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:37:48 by aprevrha          #+#    #+#             */
/*   Updated: 2023/11/07 20:59:28 by aprevrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_int_arr(int *arr, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	int tmp;
	int	*p;
	
	i = 0;
	while (i < size)
	{
		p = &arr[i];
		j = i;
		while (j < size)
		{
			if (*p < arr[j])
				p = &arr[j];
			j++;
		}
		tmp = arr[i];
		arr[i] = *p;
		*p = tmp;
		i++;
	}
}

void	get_rot(t_stk *a, int val, int *r, int *rr)
{
	*r = 0;
	*rr = 0;
	while (*r < (int)a->size && a->arr[a->size-1 - *r] != val)
		(*r)++;
	while (*rr < (int)a->size && a->arr[*rr] != val)
		(*rr)++;
	(*rr) += 1;
}

int	find_slot(t_stk *b, int val)
{
	int	i;
	while (b->arr[i] < val)
		i++;
	return (b->arr[i]);
}

int	ab(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

t_rotset	get_rotset(int val, t_stk *a, t_stk *b)
{
	t_rotset	rs;

	get_rot(a, val, &rs.ra, &rs.rra);
	get_rot(b, find_slot(b, val), &rs.rb, &rs.rrb);
	if (ab(rs.ra - rs.rb) < ab(rs.rra - rs.rrb))
	{
		rs.rra = 0;
		rs.rrb = 0;
		if (rs.ra > rs.rb)
			rs.cost = rs.ra;
		else
			rs.cost = rs.rb;
	}
	else
	{
		rs.ra = 0;
		rs.rb = 0;
		if (rs.rra > rs.rrb)
			rs.cost = rs.rra;
		else
			rs.cost = rs.rrb;
	}
	return (rs);
}

void	execute_rotset(t_rotset rs, t_stk *a, t_stk *b)
{
	while (rs.ra > 0 && rs.rb > 0)
	{
		ft_printf("rr\n");
		rotate(a);
		rotate(b);
		rs.ra--;
		rs.rb--;
	}
	while (rs.rra > 0 && rs.rrb > 0)
	{
		ft_printf("rrr\n");
		rev_rotate(a);
		rev_rotate(b);
		rs.rra--;
		rs.rrb--;
	}
	while (rs.ra > 0)
	{
		ft_printf("ra\n");
		rotate(a);
		rs.ra--;
	}
	while (rs.rb > 0)
	{
		ft_printf("rb\n");
		rotate(b);
		rs.rb--;
	}
	while (rs.rra > 0)
	{
		ft_printf("rra\n");
		rev_rotate(a);
		rs.rra--;
	}
	while (rs.rrb > 0)
	{
		ft_printf("rrb\n");
		rev_rotate(b);
		rs.rrb--;
	}
}

void	solve2(t_stk *a, t_stk *b)
{
	unsigned int	i;
	t_rotset		best_rs;
	t_rotset		rs;

	push(a, b);
	push(a, b);
	while(a->size > 0)
	{
		i = 0;
		while (i < a->size)
		{
			rs = get_rotset(a->arr[i], a, b);
			if (rs.cost < best_rs.cost)
				best_rs = rs;
			i++;
		}
	execute_rotset(best_rs, a, b);
	push(a, b);
	}
	while(b->size > 0)
	{
		push(b, a);
		ft_printf("pa\n");
	}
}
