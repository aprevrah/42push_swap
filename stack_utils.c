/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprevrha <aprevrha@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:13:53 by aprevrha          #+#    #+#             */
/*   Updated: 2023/12/10 21:48:16 by aprevrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ind(t_stk *s, int i)
{
	int	r;

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