/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprevrha <aprevrha@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:01:15 by aprevrha          #+#    #+#             */
/*   Updated: 2023/12/15 16:35:57 by aprevrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct s_rotset
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	cost;
}	t_rotset;

void	solve(t_stk *a, t_stk *b);

//utils_parsing.c
int		check_format(char **arg_strs);
char	**handle_input(int argc, char **argv);
void	print_error(char *err_msg);

//utils_oper.c
void	swap(t_stk *stk);
void	rotate(t_stk *stk);
void	rev_rotate(t_stk *stk);
void	push(t_stk *from, t_stk *to);

//utils_sort.c
int		get_max(int x, int y);
int		find_slot_ascending(t_stk *b, int val);
int		find_slot_descending(t_stk *a, int val);
void	execute_rot(t_stk *s, void (*rot_function)(t_stk *),
			char *rot_string, int n);
void	execute_rotset(t_rotset rs, t_stk *a, t_stk *b);

//utils_stack_management.c
t_stk	*init_stk(unsigned int max_size, char **arg_strs_to_free);
void	fill_stk(t_stk *stk, char **strs);
void	free_str_arr(char **strs);
void	free_stk(t_stk *s);
int		check_duplicates(t_stk *s);

//utils_stack.c
int		ind(t_stk *s, int i);
int		min(t_stk *s);
int		max(t_stk *s);
int		index_of(t_stk *s, int val);
int		last3(t_stk *s);

#endif