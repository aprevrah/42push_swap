/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprevrha <aprevrha@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:41:58 by aprevrha          #+#    #+#             */
/*   Updated: 2023/12/15 01:54:14 by aprevrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_max(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
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

void	execute_rot(t_stk *s, void (*rot_function)(t_stk *),
			char *rot_string, int n)
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
