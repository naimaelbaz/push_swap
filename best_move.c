/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:01:01 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/16 08:32:39 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_move(t_stack *stack_a, t_stack *stack_b)
{
	int		*tab;
	int		i;
	int		min_pos;
	t_stack	*tmp;

	tab = number_of_moves(stack_a, stack_b);
	min_pos = ft_min_pos(stack_b, tab);
	printf("min_pos:------>%d\n", min_pos);
	tmp = stack_b;
	i = 0;
	while (tmp != NULL)
	{
		//ft_min_pos1(tmp->position, tab[i]) 
		if ((to_pos(tmp->position) + to_pos(tab[i])) == min_pos)
			return (tmp->data);
		tmp = tmp->next;
		i++;
	}
	free (tab);
	return (0);
}

void	print_stack(t_stack *stack_a)
{
	printf("*********************************\n");
	while (stack_a != NULL)
	{
		printf("position = %d  | data = %d\n", stack_a->position, stack_a->data);
		stack_a = stack_a->next;
	}
	printf("*********************************\n");
}

void	deff_signe(t_stack **stack_a, t_stack **stack_b, int pos_a, int pos_b)
{
	int	i;
	int	j;

	i = to_pos(pos_a);
	j = to_pos(pos_b);
	while (i > 0)
	{
		if (pos_a > 0)
			rotate_a(stack_a);
		else
			rev_rotate_a(stack_a);
		i--;
	}
	while (j > 0)
	{
		if (pos_b > 0)
			rotate_b(stack_b);
		else if (pos_b < 0)
			rev_rotate_b(stack_b);
		j--;
	}
	push_a(stack_a, stack_b);
	//print_stack(*stack_a);
}

void	same_signe(t_stack **stack_a, t_stack **stack_b, int pos_a, int pos_b)
{
	int	i;
	int	j;
	int	min;

	i = to_pos(pos_a);
	j = to_pos(pos_b);
	min = min_number(i, j);
	if (pos_a > 0 && pos_b > 0)
		rrr(stack_a, stack_b, min, 0);
	else if (pos_a < 0 && pos_a < 0)
		rrr(stack_a, stack_b, min, 1);
	if (j > i)
		deff_signe(stack_a, stack_b, 0, pos_b - pos_a);
	else if (i > j)
		deff_signe(stack_a, stack_b, pos_a - pos_b, 0);
	else
		push_a(stack_a, stack_b);
	//print_stack(*stack_a);
}

void	push_best_move(t_stack **stack_a, t_stack **stack_b)
{
	int		data;
	t_stack	*tmp;
	int		len;
	int		*tab;
	int		i;

	tab = number_of_moves(*stack_a, *stack_b);
	data = best_move(*stack_a, *stack_b);
	printf("\nbest_move---->%d  ", data);
	printf("\n");
	getchar();
	i = 0;
	tmp = *stack_b;
	len = ft_lstsiz(*stack_b);
	while (tmp != NULL)
	{
		if (tmp->data == data)
		{
			if (tab[i] * tmp->position > 0)
				same_signe(stack_a, stack_b, tab[i], tmp->position);
			else if (tab[i] * tmp->position <= 0)
				deff_signe(stack_a, stack_b, tab[i], tmp->position);
			return ;
			print_stack(*stack_a);
		}
		tmp = tmp->next;
		i++;
	}
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = ft_lstsiz(*stack_b);
	while (i > 0)
	{
		push_best_move(stack_a, stack_b);
		get_index_args(*stack_a, ft_lstsiz(*stack_a));
		get_index_args(*stack_b, ft_lstsiz(*stack_b));
		// printf("--------------A-----------\n");
		// print_stack(*stack_a);
		// printf("--------------B-----------\n");
		// print_stack(*stack_b);
		i--;
	}
	get_finallist(stack_a, ft_lstsiz(*stack_a));
}