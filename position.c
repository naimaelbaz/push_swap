/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:07:09 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/16 01:50:21 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_of_a(t_stack *stack_a, int data)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*last;

	tmp = stack_a;
	first = stack_a;
	last = lst_last(stack_a);
	while (tmp != NULL)
	{
		if (data > tmp->data && data < tmp->next->data)
			return (tmp->next->position);
		else if (is_langest(stack_a, data))
			return (max_pos_a(stack_a));
		else if (data < first->data && data > last->data)
			return (0);
		tmp = tmp->next;
	}
	return (0);
}

int	*number_of_moves(t_stack *stack_a, t_stack *stack_b)
{
	int		*tab;
	int		i;
	t_stack	*tmp;

	tmp = stack_b;
	i = 0;
	tab = malloc(sizeof(int) * ft_lstsiz(stack_b));
	while (tmp != NULL)
	{
		tab[i] = position_of_a(stack_a, tmp->data);
		tmp = tmp->next;
		// printf("%d  ", tab[i]);
		i++;
	}
	// i = 0;
	// tmp = stack_b;
	// 	printf("*********************************\n");
	// 	while (tmp != NULL)
	// 	{
	// 		printf("position_A = %d  | position_B = %d\n", tab[i++], tmp->position);
	// 		tmp = tmp->next;
	// 	}
	// 	printf("*********************************\n");
	// printf("\n");
	return (tab);
}
