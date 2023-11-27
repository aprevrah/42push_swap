/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprevrha <aprevrha@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:37:48 by aprevrha          #+#    #+#             */
/*   Updated: 2023/11/27 22:33:55 by aprevrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ab(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ind(t_stk *s, int i)
{
	int r;

	r = i % (s->size);
	if (r >= 0)
		return (r);
	return (r + s->size);
}

int	min(t_stk *s)
{
	int	i;
	int	index;
	int	min;

	index = 0;
	min = s->arr[0];
	i = 1;
	while (i < (int)s->size)
	{
		if (s->arr[i] < min)
		{
			min = s->arr[i];
			index = i;
		}
		i++;
	}
	return (min);
}

int	max(t_stk *s)
{
	int	i;
	int	index;
	int	max;

	index = 0;
	max = s->arr[0];
	i = 1;
	while (i < (int)s->size)
	{
		if (s->arr[i] > max)
		{
			max = s->arr[i];
			index = i;
		}
		i++;
	}
	return (max);
}

int index_of(t_stk *s, int val)
{
	int	i;
	
	i = 0;
	while (i < (int)s->size)
	{
		if (s->arr[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

int	find_slot(t_stk *b, int val)
{
	int	mini;
	int	maxi;
	int m;
	int	i;

	i = 0;
	
	mini = min(b);
	maxi = max(b);
	m = index_of(b, mini);
	//if (val < b->arr[ind(b, m)] || val > b->arr[ind(b, m - 1)])
	if (val < mini || val > maxi)
		return (ind(b, m - 1));
	while (i < (int)b->size)
	{
		if ((val < b->arr[ind(b, m + i + 1)] && val > b->arr[ind(b, m + i)]))
			return (ind(b, m + i));
		i++;
	}
	return (ind(b, m - 1));
}



t_rotset	get_rotset(int idx_a, t_stk *a, t_stk *b)
{
	t_rotset	rs;
	int			idx_b;

	idx_b = find_slot(b, a->arr[idx_a]);
	rs.ra = a->size - 1 - idx_a;
	rs.rra = idx_a + 1;
	rs.rb = b->size - 1 - idx_b;
	rs.rrb = idx_b + 1;
	
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

void end_rot(t_stk *a)
{
	int mindex;

	mindex = index_of(a, min(a));
	if (mindex > (int)a->size / 2)
	{
		while (mindex <= (int)a->size)
		{
			ft_printf("ra\n");
			rotate(a);
			mindex++;
		}
		return ;
	}
	while (mindex >= 0)
		{
			ft_printf("rra\n");
			rev_rotate(a);
			mindex--;
		}
}

void	solve2(t_stk *a, t_stk *b)
{
	unsigned int	i;
	t_rotset		best_rs;
	t_rotset		rs;

	push(a, b);
	push(a, b);
	ft_printf("pb\n");
	ft_printf("pb\n");
	while(a->size > 0)
	{
		i = 0;
		best_rs.cost = 100000;
		while (i < a->size)
		{
			rs = get_rotset(i, a, b);
			if (rs.cost < best_rs.cost)
				best_rs = rs;
			i++;
		}
		execute_rotset(best_rs, a, b);
		push(a, b);
		ft_printf("pb\n");
	}
	while(b->size > 0)
	{
		push(b, a);
		ft_printf("pa\n");
	}
	end_rot(a);
}
