/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprevrha <aprevrha@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:37:48 by aprevrha          #+#    #+#             */
/*   Updated: 2023/12/15 03:12:32 by aprevrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_rotset	get_rotset(int idx_from, t_stk *a, t_stk *b)
{
	t_rotset	rs;
	int			idx_to;
	int			min_moves;

	idx_to = find_slot_ascending(b, a->arr[idx_from]);
	rs.ra = a->size - 1 - idx_from;
	rs.rra = idx_from + 1;
	rs.rb = b->size - 1 - idx_to;
	rs.rrb = idx_to + 1;
	min_moves = get_max(rs.ra, rs.rb);
	if (min_moves > get_max(rs.rra, rs.rrb))
		min_moves = get_max(rs.rra, rs.rrb);
	if (min_moves > rs.ra + rs.rrb)
		min_moves = rs.ra + rs.rrb;
	if (min_moves > rs.rra + rs.rb)
		min_moves = rs.rra + rs.rb;
	rs.cost = min_moves;
	if (get_max(rs.ra, rs.rb) == min_moves)
		return (rs.rra = 0, rs.rrb = 0, rs);
	else if (get_max(rs.rra, rs.rrb) == min_moves)
		return (rs.ra = 0, rs.rb = 0, rs);
	else if (rs.ra + rs.rrb == min_moves)
		return (rs.rra = 0, rs.rb = 0, rs);
	return (rs.ra = 0, rs.rrb = 0, rs);
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

void	smart_sort(t_stk *a, t_stk *b, int rest)
{
	unsigned int	i;
	t_rotset		best_rs;
	t_rotset		rs;

	while ((int)a->size > rest)
	{
		if (b->size >= 2)
		{
			i = 0;
			best_rs.cost = 2147483647;
			while (i < a->size)
			{
				rs = get_rotset(i, a, b);
				if (rs.cost <= best_rs.cost)
					best_rs = rs;
				i++;
			}
			execute_rotset(best_rs, a, b);
		}
		push(a, b);
		ft_printf("pb\n");
	}
}

void	dumb_sort(t_stk *b, t_stk *a)
{
	int	slot;

	while ((int)b->size > 0)
	{
		slot = find_slot_descending(a, b->arr[b->size - 1]);
		if (slot >= (int)a->size / 2)
			execute_rot(a, rotate, "ra", a->size - slot - 1);
		else
			execute_rot(a, rev_rotate, "rra", slot + 1);
		push(b, a);
		ft_printf("pa\n");
	}
}

void	solve(t_stk *a, t_stk *b)
{
	int	rest;

	rest = 3;
	if (a->max_size > 80)
		rest = (int)(0.055 * a->max_size + 10.5);
	smart_sort(a, b, rest);
	while (a->size > 3)
	{
		push(a, b);
		ft_printf("pb\n");
	}
	last3(a);
	dumb_sort(b, a);
	end_rot(a);
}
