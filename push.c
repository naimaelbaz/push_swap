/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:10:24 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/14 17:54:38 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;

	if (*stack1 == NULL)
		return ;
	if ((*stack1)->next != NULL)
	{
		tmp = (*stack1)->next;
		if (*stack2 == NULL)
			(*stack1)->next = NULL;
		else
			(*stack1)->next = *stack2;
		*stack2 = *stack1;
		*stack1 = tmp;
		(*stack1)->prev = NULL;
	}
	else
	{
		(*stack1)->next = *stack2;
		*stack2 = *stack1;
		*stack1 = NULL;
	}
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}

// int	main(int argc, char **argv)
// {
// 	t_stack			*stack_a;
// 	t_stack			*stack_b;
// 	t_stack			*stack;

// 	if (argc > 1)
// 	{
// 		stack_b = NULL;
// 		stack_a = get_list(argc, argv, 1);
// 		stack = stack_a;
// 		while (stack_a != NULL)
// 		{
// 			printf("%d\n", stack_a->data);
// 			stack_a = stack_a->next;
// 		}
// 		printf("--------    -----------\n");
// 		push(&stack, &stack_b);
// 		push(&stack, &stack_b);
// 		push(&stack, &stack_b);
// 		push(&stack, &stack_b);
// 		push(&stack, &stack_b);
// 		push(&stack_b, &stack);
// 		while (stack != NULL)
// 		{
// 			printf("%d\n", stack->data);
// 			stack = stack->next;
// 		}
// 		printf("----------------------------\n");
// 		while (stack_b != NULL)
// 		{
// 			printf("|%d|\n", stack_b->data);
// 			stack_b = stack_b->next;
// 		}
// 	}
// }
