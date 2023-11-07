/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprevrha <aprevrha@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:41:34 by aprevrha          #+#    #+#             */
/*   Updated: 2023/11/07 17:54:33 by aprevrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stk *stk)
{
	int	swap;
	
	if (stk->size < 2)
		return ;
	swap = stk->arr[stk->size - 1];
	stk->arr[stk->size - 1] = stk->arr[stk->size - 2];
	stk->arr[stk->size - 2] = swap;
}

void	rotate(t_stk *stk)
{
	unsigned int	i;
	int 			tmp;
	
	if (stk->size < 2)
		return ;
	tmp = stk->arr[stk->size - 1];
	i = stk->size - 1;
	while (i > 0)
	{
		stk->arr[i] = stk->arr[i - 1];
		i--;
	}
	stk->arr[0] = tmp;
}

void	rev_rotate(t_stk *stk)
{
	unsigned int	i;
	int 			tmp;
	
	if (stk->size < 2)
		return ;
	tmp = stk->arr[0];
	i = 0;
	while (i < stk->size - 1)
	{
		stk->arr[i] = stk->arr[i + 1];
		i++;
	}
	stk->arr[stk->size - 1] = tmp;
}

void	push(t_stk *from, t_stk *to)
{
	if (from->size == 0)
		return ;
	to->arr[to->size] = from->arr[from->size - 1];
	to->size++;
	from->size--;
}
