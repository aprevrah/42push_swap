/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprevrha <aprevrha@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:01:15 by aprevrha          #+#    #+#             */
/*   Updated: 2023/12/13 21:06:32 by aprevrha         ###   ########.fr       */
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

typedef struct s_rotset
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	cost;
}	t_rotset;

void		swap(t_stk *stk);
void		rotate(t_stk *stk);
void		rev_rotate(t_stk *stk);
void		push(t_stk *from, t_stk *to);

void		solve(t_stk *a, t_stk *b);

int			ind(t_stk *s, int i);
int			min(t_stk *s);
int			max(t_stk *s);
int			index_of(t_stk *s, int val);

int			last3(t_stk *s);

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