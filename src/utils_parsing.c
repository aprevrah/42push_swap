/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprevrha <aprevrha@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 22:36:43 by aprevrha          #+#    #+#             */
/*   Updated: 2023/12/15 01:54:34 by aprevrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_num(char *str)
{
	int	len;

	len = 0;
	if (str[len] == '-')
		len++;
	while (str[len])
	{
		if (!ft_isdigit(str[len]))
			return (0);
		len++;
	}
	return (len);
}

int	is_overflow(char *str)
{
	int		is_min;
	int		i;
	char	*max_int;

	max_int = "2147483647";
	is_min = 0;
	i = 0;
	if (*str == '-')
	{
		str++;
		is_min = 1;
	}
	while (str[i])
	{
		if (str[i] > max_int[i])
		{
			if (i >= 9 && is_min && str[i] <= '8')
				return (0);
			return (1);
		}
		else if (str[i] < max_int[i])
			return (0);
		i++;
	}
	return (0);
}

int	check_format(char **arg_strs)
{
	int	i;
	int	len;

	i = 0;
	while (arg_strs[i])
	{
		len = is_num(arg_strs[i]);
		if (len == 0 || len > 11)
			return (1);
		else if (len >= 10 && is_overflow(arg_strs[i]))
			return (1);
		i++;
	}
	return (0);
}

char	**handle_input(int argc, char **argv)
{
	char	**arg_strs;
	int		i;

	i = 0;
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
	return (arg_strs);
}

void	print_error(char *err_msg)
{
	if (VERBOSE_ERR)
	{
		ft_putstr_fd("\033[41mError:\033[0m ", 1);
		ft_putendl_fd(err_msg, 1);
	}
	else
		ft_putendl_fd("Error", 1);
}
