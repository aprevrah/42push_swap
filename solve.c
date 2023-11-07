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

int	find_next(t_stk *stk, int min)
{
	int	r;
	int	rr;

	r = 0;
	rr = 0;
	while (r < (int)stk->size && stk->arr[stk->size-1 - r] < min)
		r++;
	while (r < (int)stk->size && stk->arr[rr] < min)
		rr++;
	if (r >= (int)stk->size)
		return (2);
	if (r == 0)
		return (0);
	else if (r > rr)
		return (-1);
	else
		return (1);
}


void	solve(t_stk *a, t_stk *b, t_stk *c)
{
	unsigned int	i;
	int				min;
	int				next;
	unsigned int	buckets;

	buckets = 12;
	sort_int_arr(c->arr, c->size);
	i = 1;
	while (i <= buckets)
	{
		min = c->arr[c->size/buckets * i];
		ft_printf("min: %d\n", min);
		while (1)
		{
			next = find_next(a, min);
			if (next == 2)
				break;
			while (next == 1 && a->arr[a->size - 1] < min)
			{
				rotate(a);
				ft_printf("ra\n");
			}
			while (next == -1 && a->arr[a->size - 1] < min)
			{
				rev_rotate(a);
				ft_printf("rra\n");
			}
			push(a, b);
			ft_printf("pb\n");
		}
		i++;
	}
	i = 0;
	
	while(i < c->size)
	{
		min = c->arr[i];
		next = find_next(b, min);
		while (next == 1 && b->arr[b->size - 1] < min)
		{
			rotate(b);
			ft_printf("rb\n");
		}
		while (next == -1 && b->arr[b->size - 1] < min)
		{
			rev_rotate(b);
			ft_printf("rrb\n");
		}
		push(b, a);
		ft_printf("pa\n");
		i++;
	}
}