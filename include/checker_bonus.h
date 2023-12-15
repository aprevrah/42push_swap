/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprevrha <aprevrha@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:01:15 by aprevrha          #+#    #+#             */
/*   Updated: 2023/12/15 03:18:48 by aprevrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

# define VERBOSE_ERR 0

typedef struct s_stk
{
	int				*arr;
	unsigned int	size;
	unsigned int	max_size;
}	t_stk;

//utils_parsing.c
int		check_format(char **arg_strs);
char	**handle_input(int argc, char **argv);

//utils_oper.c
void	swap(t_stk *stk);
void	rotate(t_stk *stk);
void	rev_rotate(t_stk *stk);
void	push(t_stk *from, t_stk *to);

//utils_stack_management.c
t_stk	*init_stk(unsigned int max_size);
void	fill_stk(t_stk *stk, char **strs);
void	free_str_arr(char **strs);
void	free_stk(t_stk *s);
int		check_duplicates(t_stk *s);

#endif