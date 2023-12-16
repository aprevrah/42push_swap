/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_management.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprevrha <aprevrha@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:19:55 by aprevrha          #+#    #+#             */
/*   Updated: 2023/12/15 16:36:31 by aprevrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stk	*init_stk(unsigned int max_size, char **arg_strs_to_free)
{
	t_stk	*stk;

	stk = (t_stk *)malloc(sizeof(t_stk));
	if (!stk)
	{
		free_str_arr(arg_strs_to_free);
		print_error("Malloc error while creating stack");
		exit(1);
	}
	stk->size = 0;
	stk->max_size = max_size;
	stk->arr = (int *)malloc(sizeof(int) * max_size);
	if (!stk->arr)
	{
		free(stk);
		print_error("Malloc error while creating stack array");
		exit(1);
	}
	return (stk);
}

void	fill_stk(t_stk *stk, char **strs)
{
	int		i;

	i = 0;
	while (strs[i])
	{
		stk->arr[stk->max_size - i - 1] = ft_atoi(strs[i]);
		i++;
	}
	stk->size = i;
}

void	free_str_arr(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	free_stk(t_stk *s)
{
	free(s->arr);
	free(s);
}

int	check_duplicates(t_stk *s)
{
	int	sorted;
	int	i;
	int	j;

	sorted = 2;
	i = 0;
	while (i < (int)s->size)
	{
		if (i < (int)s->size - 1 && s->arr[i] < s->arr[i + 1])
			sorted = 0;
		j = i + 1;
		while (j < (int)s->size)
		{
			if (s->arr[i] == s->arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (sorted);
}
