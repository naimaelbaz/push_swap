/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:23:31 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/17 01:24:07 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	to_pos(int tab)
{
	if (tab < 0)
		tab *= -1;
	return (tab);
}

int	ft_min_pos(t_stack	*stack_b, int *tab)
{
	t_stack	*tmp;
	int		min_pos;
	int		i;

	tmp = stack_b;
	i = 0;
	min_pos = to_pos(tab[i++]) + to_pos(tmp->position);
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (min_pos > (to_pos(tab[i]) + to_pos(tmp->position)))
			min_pos = to_pos(tab[i]) + to_pos(tmp->position);
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}

// int	ft_min_pos1(int pos_b, int pos_a)
// {
// 	int		min_pos;

// 	if (pos_a > 0 && pos_b > 0)
// 	{
// 		if (pos_a > pos_b)
// 			min_pos = pos_a;
// 		else
// 			min_pos = pos_b;
// 	}
// 	else if (pos_a < 0 && pos_b < 0)
// 	{
// 		if (pos_a < pos_b)
// 			min_pos = pos_a;
// 		else
// 			min_pos = pos_b;
// 	}
// 	else
// 		min_pos = to_pos(pos_a) + to_pos(pos_b);
// 	return (to_pos(min_pos));
// }

// int	ft_min_pos(t_stack	*stack_b, int *tab)
// {
// 	t_stack	*tmp;
// 	int		min_pos;
// 	int		i;

// 	tmp = stack_b;
// 	i = 0;
// 	min_pos = ft_min_pos1(tmp->position, tab[i]);
// 	tmp = tmp->next;
// 	while (tmp != NULL)
// 	{
// 		if (min_pos > ft_min_pos1(tmp->position, tab[i]))
// 			min_pos = ft_min_pos1(tmp->position, tab[i]);
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	return (min_pos);
// }

int	min_number(int i, int j)
{
	int	min;

	min = 0;
	if (i > j)
		min = j;
	else if (j >= i)
		min = i;
	return (min);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int com, int a)
{
	while (com)
	{
		if (a == 0)
			rotate_ab(stack_a, stack_b);
		else if (a == 1)
			rev_rotate_ab(stack_a, stack_b);
		com--;
	}
}

void	get_finallist(t_stack **stack_tmp, int size)
{
	int			pos;
	int			min;

	pos = get_position(*stack_tmp);
	min = have_min_number(*stack_tmp);
	while ((*stack_tmp)->data != min)
	{
		if (pos <= (size / 2))
			rotate_a(stack_tmp);
		else if (pos > (size / 2))
			rev_rotate_a(stack_tmp);
	}
}
