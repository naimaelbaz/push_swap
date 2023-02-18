/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:56:21 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/18 04:31:31 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
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

//void		swap(t_stack *stack);
// void		rotate(t_stack **stack);
// void		rev_rotate(t_stack **stack);
// void		push(t_stack **stack1, t_stack **stack2);
void		push_a(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_b, t_stack **stack_a);
void		rev_rotate_a(t_stack **stack_a);
void		rev_rotate_b(t_stack **stack_b);
void		rev_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void		rotate_a(t_stack **stack_a);
void		rotate_b(t_stack **stack_b);
void		rotate_ab(t_stack **stack_a, t_stack **stack_b);

int			*get_lis(int *tab, int size);
t_stack		*get_list(int size_list, char **data);
t_stack		*check_numberofarg(int size, char **argv, t_stack *stack_a);
char		**ft_split(const char *s, char c);
int			*get_lis(int *tab, int size);
int			max_len(int *len_tab, int size);
t_stack		*new_stack_a(t_stack *stack_a, int *tab, int size);
t_stack		*pushin_b(t_stack *stack_a, int *tab, int size);
int			a_is_integer(char *argv);
int			a_duplicate(char **argv, int argc);
int			check_arg(char **argv, int argc);
void		exit_fun(void);

t_stack		*get_duplist(t_stack *stack_tmp, int size);
void		rev_rotate_a(t_stack **stack);
void		rotate_a(t_stack **stack);
t_stack		*newlist(int data);
t_stack		*copy_list(t_stack *stack_a);
int			get_position(t_stack *stack_a);
int			get_position(t_stack *stack_a);
int			have_min_number(t_stack *stack_a);
t_stack		*get_newlist(t_stack *stack_tmp, int size);
int			*convert_to_array(t_stack *stack_tmp, int size);

void		insert_tab(int *index_tab, int *len_tab, int size);
int			*get_length(int *tab, int size);
int			*get_index_tab(int *tab, int size);
int			get_index(int *len_tab, int size);
int			max_len(int *len_tab, int size);

t_stack		*pb(t_stack **stack_a, t_stack *stack_b, int size);
void		rotate_a_tmp(t_stack **stack_a);
void		rev_rotate_a_tmp(t_stack **stack);
int			check_size(t_stack *stack_a, int *tab_lis, int *tab, int size);
int			ft_lstsiz(t_stack *lst);
void		get_index_args(t_stack *stack, int size_stack);
int			is_langest(t_stack *stack, int data);
t_stack		*lst_last(t_stack *lst);
int			max_pos_a(t_stack *stack);
int			is_smallest(t_stack *stack, int data);
int			position_of_a(t_stack *stack_a, int data);
int			*number_of_moves(t_stack *stack_a, t_stack *stack_b);
void		push_to_a(t_stack **stack_a, t_stack **stack_b);

int			to_pos(int tab);
int			ft_min_pos(t_stack	*stack_b, int *tab);
int			min_number(int i, int j);
void		rrr(t_stack **stack_a, t_stack **stack_b, int com, int a);
void		get_finallist(t_stack **stack_tmp, int size);
void		print_stack(t_stack *stack_a);
int			ft_min_pos1(int pos_b, int pos_a);
void		exit_fun(void);
int			mid_value(t_stack *stack_a);
#endif