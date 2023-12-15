/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprevrha <aprevrha@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:13:53 by aprevrha          #+#    #+#             */
/*   Updated: 2023/12/15 01:54:27 by aprevrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ind(t_stk *s, int i)
{
	int	r;

	if ((int)s->size < 1)
		return (-1);
	r = i % (int)s->size;
	if (r >= 0)
		return (r);
	return (r + s->size);
}

int	min(t_stk *s)
{
	int	i;
	int	min;

	min = s->arr[0];
	i = 1;
	while (i < (int)s->size)
	{
		if (s->arr[i] < min)
			min = s->arr[i];
		i++;
	}
	return (min);
}

int	max(t_stk *s)
{
	int	i;
	int	max;

	max = s->arr[0];
	i = 1;
	while (i < (int)s->size)
	{
		if (s->arr[i] > max)
			max = s->arr[i];
		i++;
	}
	return (max);
}

int	index_of(t_stk *s, int val)
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

int	last3(t_stk *s)
{
	if (s->arr[0] > s->arr[1] && s->arr[0] > s->arr[2])
	{
		if (s->arr[1] < s->arr[2])
			return (swap(s), ft_printf("sa\n"), 0);
		else
			return (0);
	}
	else if (s->arr[0] < s->arr[1] && s->arr[0] < s->arr[2])
	{
		if (s->arr[1] < s->arr[2])
			return (swap(s), ft_printf("sa\n"), 0);
		else
			return (0);
	}
	else
	{
		if (s->arr[1] < s->arr[2])
			return (0);
		else
			return (swap(s), ft_printf("sa\n"), 0);
	}
	return (1);
}

// All the different cases:
// 2 1  3 2  3 1
// 1 2  2 3  1 3
// 3 3  1 1  2 2
/* Full sort with rotate
int	last3(t_stk *s)
{
	if (s->arr[0] > s->arr[1] && s->arr[0] > s->arr[2])
	{
		if (s->arr[1] < s->arr[2])
			return (swap(s), ft_printf("sa\n"), 0);
		else
			return (0);
	}
	else if (s->arr[0] < s->arr[1] && s->arr[0] < s->arr[2])
	{
		if (s->arr[1] < s->arr[2])
			return (rotate(s), swap(s), ft_printf("ra\nsa\n"), 0);
		else
			return (rev_rotate(s), ft_printf("rra\n"), 0);
	}
	else
	{
		if (s->arr[1] < s->arr[2])
			return (rotate(s), ft_printf("ra\n"), 0);
		else
			return (rev_rotate(s), swap(s), ft_printf("rra\nsa\n"), 0);
	}
	return (1);
} 
*/