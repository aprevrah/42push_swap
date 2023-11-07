/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprevrha <aprevrha@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:01:15 by aprevrha          #+#    #+#             */
/*   Updated: 2023/11/07 16:46:12 by aprevrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stk
{
	int				*arr;
	unsigned int	size;
	unsigned int	max_size;
}	t_stk;


typedef struct s_tab
{
	t_stk	*stk_a;
	t_stk	*stk_b;
}	t_tab;

void		swap(t_stk *stk);
void		rotate(t_stk *stk);
void		rev_rotate(t_stk *stk);
void		push(t_stk *from, t_stk *to);

void		solve(t_stk *a, t_stk *b, t_stk *c);
/*
void		pa(t_tab tab);
void		pb(t_tab tab);
void		ss(t_tab tab);
void		sa(t_tab tab);
void		sb(t_tab tab);
void		ra(t_tab tab);
void		rb(t_tab tab);
void		rr(t_tab tab);
void		rra(t_tab tab);
void		rrb(t_tab tab);
void		rrr(t_tab tab);
*/

/*  */