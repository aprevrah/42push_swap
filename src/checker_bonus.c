/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprevrha <aprevrha@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 22:34:46 by aprevrha          #+#    #+#             */
/*   Updated: 2023/12/15 16:57:36 by aprevrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	p_err_nnl(char *err_msg)
{
	if (VERBOSE_ERR)
	{
		ft_putstr_fd("\033[41mError:\033[0m ", 1);
		ft_putstr_fd(err_msg, 1);
	}
	else
		ft_putendl_fd("Error", 1);
}

int	execute_oper(t_stk	*a, t_stk	*b, char	*oper)
{
	if (!ft_strncmp(oper, "pa\n", ft_strlen(oper)))
		push(b, a);
	else if (!ft_strncmp(oper, "pb\n", ft_strlen(oper)))
		push(a, b);
	else if (!ft_strncmp(oper, "sa\n", ft_strlen(oper)))
		swap(a);
	else if (!ft_strncmp(oper, "sb\n", ft_strlen(oper)))
		swap(b);
	else if (!ft_strncmp(oper, "ra\n", ft_strlen(oper)))
		rotate(a);
	else if (!ft_strncmp(oper, "rb\n", ft_strlen(oper)))
		rotate(b);
	else if (!ft_strncmp(oper, "rra\n", ft_strlen(oper)))
		rev_rotate(a);
	else if (!ft_strncmp(oper, "rrb\n", ft_strlen(oper)))
		rev_rotate(b);
	else if (!ft_strncmp(oper, "rr\n", ft_strlen(oper)))
		return (rotate(a), rotate(b), 0);
	else if (!ft_strncmp(oper, "rrr\n", ft_strlen(oper)))
		return (rev_rotate(a), rev_rotate(b), 0);
	else
		return (1);
	return (0);
}

int	check(t_stk	*a, t_stk	*b)
{
	int		errors;
	char	*oper;

	errors = 0;
	oper = get_next_line(0);
	while (oper != NULL)
	{
		errors += execute_oper(a, b, oper);
		free(oper);
		oper = get_next_line(0);
	}
	if (errors)
	{
		if (VERBOSE_ERR)
			return (p_err_nnl("Error(s): "),
				ft_putnbr_fd(errors, 1), ft_putchar_fd('\n', 1), 1);
		return (1);
	}
	else if (b->size != 0 || check_duplicates(a) != 2)
		return (2);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**arg_strs;
	t_stk	*a;
	t_stk	*b;
	int		i;

	arg_strs = handle_input(argc, argv);
	if (!arg_strs)
		return (p_err_nnl("EmptyStr or malloc error while parsing input\n"), 1);
	if (check_format(arg_strs))
		return (p_err_nnl("Invalid format\n"), free_str_arr(arg_strs), 1);
	i = 0;
	while (arg_strs[i])
		i++;
	a = init_stk(i, arg_strs);
	b = init_stk(i, arg_strs);
	fill_stk(a, arg_strs);
	free_str_arr(arg_strs);
	if (check_duplicates(a) == 1)
		return (p_err_nnl("Duplicates found\n"), free_stk(a), free_stk(b), 1);
	i = check(a, b);
	if (i == 1)
		return (p_err_nnl("Invalid oporations\n"), free_stk(a), free_stk(b), 1);
	else if (i == 2)
		return (ft_putendl_fd("KO", 1), free_stk(a), free_stk(b), 0);
	return (ft_putendl_fd("OK", 1), free_stk(a), free_stk(b), 0);
}
