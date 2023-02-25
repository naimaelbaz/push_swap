/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:56:21 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/25 23:06:24 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <ctype.h>

typedef struct list
{
	struct list	*prev;
	int			data;
	int			position;
	struct list	*next;
}t_stack;

void		push_a(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_b, t_stack **stack_a);
void		rev_rotate_a(t_stack **stack_a);
void		rev_rotate_b(t_stack **stack_b);
void		rev_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void		rotate_a(t_stack **stack_a);
void		rotate_b(t_stack **stack_b);
void		rotate_ab(t_stack **stack_a, t_stack **stack_b);
void		swap_a(t_stack *stack_a);
void		swap_b(t_stack *stack_b);
t_stack		*get_list(int size_list, char **data);
t_stack		*check_numberofarg(int size, char **argv, t_stack *stack_a);
char		**ft_split(const char *s, char c);
int			a_is_integer(char *argv);
int			a_duplicate(char **argv, int argc);
int			check_arg(char **argv, int argc);
void		exit_fun(void);
t_stack		*newlist(int data);
int			check_size(t_stack *stack_a, int *tab_lis, int *tab, int size);
int			ft_lstsiz(t_stack *lst);
t_stack		*lst_last(t_stack *lst);
int			a_is_sorted(t_stack	*stack_a);
void		free_stack(t_stack **stack);
int			b_is_empty(t_stack *stack_b);
void		check_mv_2(t_stack **stack_a, t_stack **stack_b, char *mv);
void		check_mv_3(t_stack **stack_a, t_stack **stack_b, char *mv);
void		exit_error(t_stack *stack_a, t_stack *stack_b);
#endif