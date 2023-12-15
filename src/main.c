/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprevrha <aprevrha@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:20:03 by aprevrha          #+#    #+#             */
/*   Updated: 2023/12/15 01:54:09 by aprevrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	char	**arg_strs;
	t_stk	*a;
	t_stk	*b;
	int		i;

	arg_strs = handle_input(argc, argv);
	if (check_format(arg_strs))
		return (print_error("Invalid format"), free_str_arr(arg_strs), 1);
	i = 0;
	while (arg_strs[i])
		i++;
	a = init_stk(i);
	b = init_stk(i);
	fill_stk(a, arg_strs);
	free_str_arr(arg_strs);
	i = check_duplicates(a);
	if (i == 1)
		return (print_error("Duplicates found"), free_stk(a), free_stk(b), 1);
	else if (i == 2)
		return (free_stk(a), free_stk(b), 0);
	solve(a, b);
	return (free_stk(a), free_stk(b), 0);
}
