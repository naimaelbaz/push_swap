/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:54:16 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/13 16:45:07 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*node;
	t_stack	*last_node;

	node = *stack;
	while (node && node->next->next != NULL)
		node = node->next;
	last_node = node->next;
	node->next = NULL;
	last_node->prev = NULL;
	last_node->next = *stack;
	(*stack)->prev = last_node;
	*stack = last_node;
}

void	rev_rotate_a(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rev_rotate_a_tmp(t_stack **stack_a)
{
	rev_rotate(stack_a);
}

void	rev_rotate_b(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rev_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}

// int	main(int argc, char **argv)
// {
// 	t_stack			*stack_a;

// 	if (argc > 1)
// 	{
// 		stack_a = get_list(argc, argv, 1);
// 		// while (stack_a != NULL)
// 		// {
// 		// 	printf("%d\n",stack_a->data);
// 		// 	stack_a = stack_a->next;
// 		// }
// 		rev_rotate(&stack_a);
// 		while (stack_a != NULL)
// 		{
// 			printf("%d\n",stack_a->data);
// 			stack_a = stack_a->next;
// 		}
// 	}
// }
