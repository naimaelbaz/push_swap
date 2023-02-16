/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:19:06 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/14 11:02:53 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*str;

	tmp = (*stack)->next;
	str = *stack;
	while (str && str->next != NULL)
		str = str->next;
	str->next = *stack;
	(*stack)->prev = str;
	(*stack)->next = NULL;
	*stack = tmp;
	(*stack)->prev = NULL;
}

void	rotate_a(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_a_tmp(t_stack **stack_a)
{
	rotate(stack_a);
}

void	rotate_b(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
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
// 		// rotate(&stack_a);
// 		// rotate(&stack_a);
// 		// while (stack_a != NULL)
// 		// {
// 		// 	printf("%d\n",stack_a->data);
// 		// 	stack_a = stack_a->next;
// 		// }
// 	}
// }
