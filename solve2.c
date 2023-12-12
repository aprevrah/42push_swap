/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprevrha <aprevrha@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:37:48 by aprevrha          #+#    #+#             */
/*   Updated: 2023/12/13 00:39:24 by aprevrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ab(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	find_slot_ascending(t_stk *b, int val)
{
	int	mini;
	int	maxi;
	int	m;
	int	i;

	i = 0;
	mini = min(b);
	maxi = max(b);
	m = index_of(b, mini);
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

int	find_slot_descending(t_stk *a, int val)
{
	int	mini;
	int	maxi;
	int	m;
	int	i;

	i = 0;
	mini = min(a);
	maxi = max(a);
	m = index_of(a, maxi);
	if (val < mini || val > maxi)
		return (ind(a, m - 1));
	while (i < (int)a->size)
	{
		if ((val < a->arr[ind(a, m + i)] && val > a->arr[ind(a, m + i + 1)]))
			return (ind(a, m + i));
		i++;
	}
	return (ind(a, m - 1));
}

t_rotset	get_rotset(int idx_from, t_stk *a, t_stk *b, int to_b)
{
	t_rotset	rs;
	int			idx_to;
	
	if (to_b)
	{
		idx_to = find_slot_ascending(b, a->arr[idx_from]);
		rs.ra = a->size - 1 - idx_from;
		rs.rra = idx_from + 1;
		rs.rb = b->size - 1 - idx_to;
		rs.rrb = idx_to + 1;
	}
	else 
	{
		idx_to = find_slot_descending(a, b->arr[idx_from]);
		rs.ra = a->size - 1 - idx_to;
		rs.rra = idx_to + 1;
		rs.rb = b->size - 1 - idx_from;
		rs.rrb = idx_from + 1;
	}
	if (ab(rs.ra - rs.rb) < ab(rs.rra - rs.rrb))
	{
		rs.rra = 0;
		rs.rrb = 0;
		if (rs.ra > rs.rb)
			return (rs.cost = rs.ra, rs);
		else
			return (rs.cost = rs.rb, rs);
	}
		rs.ra = 0;
		rs.rb = 0;
		if (rs.rra > rs.rrb)
			return (rs.cost = rs.rra, rs);
		else
			return (rs.cost = rs.rrb, rs);
	return (rs);
}

void	execute_rot(t_stk *s, void (*rot_function)(t_stk *), char *rot_string, int n)
{
	while (n > 0)
	{
		ft_printf("%s\n", rot_string);
		rot_function(s);
		n--;
	}
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
	execute_rot(a, rotate, "ra", rs.ra);
	execute_rot(a, rev_rotate, "rra", rs.rra);
	execute_rot(b, rotate, "rb", rs.rb);
	execute_rot(b, rev_rotate, "rrb", rs.rrb);
}

void	end_rot(t_stk *a)
{
	int	max_index;

	max_index = index_of(a, max(a));
	if (max_index > (int)a->size / 2)
	{
		while (max_index < (int)a->size)
		{
			ft_printf("ra\n");
			rotate(a);
			max_index++;
		}
		return ;
	}
	while (max_index > 0)
	{
		ft_printf("rra\n");
		rev_rotate(a);
		max_index--;
	}
}

void	smart_sort(t_stk *a, t_stk *b, int to_b, int rest)
{
	unsigned int	i;
	t_rotset		best_rs;
	t_rotset		rs;
	t_stk			*from;
	t_stk			*to;

	if (to_b)
	{
		from = a;
		to = b;
	}
	else
	{
		from = b;
		to = a;
	}
	while ((int)from->size > rest)
	{
		if (to->size >= 2)
		{
			i = 0;
			best_rs.cost = 2147483647;
			while (i < from->size)
			{
				rs = get_rotset(i, a, b, to_b);
				if (rs.cost <= best_rs.cost)
					best_rs = rs;
				i++;
			}
			execute_rotset(best_rs, a, b);
		}
		push(from, to);
		if (to_b)
			ft_printf("pb\n");
		else
			ft_printf("pa\n");
	}
}

void	solve2(t_stk *a, t_stk *b)
{
	int slot;
	// while (a->size > 0)
	// {
	// 	push(a, b);
	// 	ft_printf("pb\n");
	// }
	smart_sort(a, b, 1, 20);
	while (a->size > 3)
	{
		push(a, b);
		ft_printf("pb\n");
	}
	last3(a);
	smart_sort(a, b, 0, 77);
	//smart_sort(a, b, 0, 0);
	while ((int)b->size > 0)
	{
		slot = find_slot_descending(a, b->arr[b->size - 1]);
		if (slot > (int)a->size / 2)
			execute_rot(a, rotate, "ra", a->size - slot - 1);
		else
			execute_rot(a, rev_rotate, "rra", slot + 1);
		push(b, a);
		ft_printf("pa\n");
	}
	end_rot(a);
}

