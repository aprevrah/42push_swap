/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprevrha <aprevrha@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:20:03 by aprevrha          #+#    #+#             */
/*   Updated: 2023/11/28 20:20:48 by aprevrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
	}
	return (1);
}
/* 
void	check_format(char **arg_strs)
{
	int	i;

	i = 0;
	while (arg_strs[i])
	{
		
	}
} */

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

t_stk	*init_stk(unsigned int max_size)
{
	t_stk	*stk;

	stk = (t_stk *)malloc(sizeof(t_stk));
	
	stk->size = 0;
	stk->max_size = max_size;
	stk->arr = (int *)malloc(sizeof(int)* max_size);
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
void	print_stks(t_stk *stk_a, t_stk *stk_b)
{
	unsigned int i;
	
	ft_printf("STK A:");
	i = 0;
	while (i < stk_a->size)
	{
		ft_printf(" %d", stk_a->arr[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("STK B:");
	i = 0;
	while (i < stk_b->size)
	{
		ft_printf(" %d", stk_b->arr[i]);
		i++;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	char	**arg_strs;
	int		i;
	t_stk	*a;
	t_stk	*b;
	t_stk	*c;

	i = 0;
	if (argc < 2)
		return (1);
	if (argc == 2)
		arg_strs = ft_split(argv[1], ' ');
	else
	{
		arg_strs = (char **)malloc(sizeof(char *) * argc);
		while (i + 1 < argc)
		{
			arg_strs[i] = ft_strdup(argv[i + 1]);
			i++;
		}
		arg_strs[i] = NULL;
	}
	
	while (arg_strs[i])
		i++;
	a = init_stk(i);
	b = init_stk(i);
	c = init_stk(i);
	fill_stk(a, arg_strs);
	fill_stk(c, arg_strs);
	solve2(a, b);
	//solve(a, b, c);
	free_str_arr(arg_strs);
	//print_stks(a, b);
	
	//sort_stk(stk_a);
}



/* 
t_node	*nodenew(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

t_node	*nodelast(t_node *node)
{
	while (node && node->next)
	{
		node = node->next;
	}
	return (node);
}

void	nodeadd_front(t_node **node, t_node *new)
{
	new->next = *node;
	*node = new;
}

void	nodeadd_back(t_node **node, t_node *new)
{
	if ((*node)->next == NULL)
	{
		(*node)->next = new;
		return ;
	}
	nodelast(*node)->next = new;
}

append(int value)
{
	
}
 */