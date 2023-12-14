/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprevrha <aprevrha@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:52:08 by aprevrha          #+#    #+#             */
/*   Updated: 2023/12/14 17:57:08 by aprevrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// All the different cases:
// 2 1  3 2  3 1
// 1 2  2 3  1 3
// 3 3  1 1  2 2

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