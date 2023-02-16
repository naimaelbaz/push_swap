/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:38:32 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/02 11:46:30 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int			tmp;
	t_stack	*str;

	str = stack->next;
	if (stack == NULL || str == NULL)
		return ;
	tmp = stack->data;
	stack->data = str->data;
	str->data = tmp;
}

void	swap_a(t_stack *stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stack *stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}


// int	main(int argc, char **argv)
// {
// 	t_stack			*stack_a;
// 	//t_stack			*stack_b;

// 	if (argc > 1)
// 	{
// 		//stack_b = malloc(sizeof(t_stack));
// 		stack_a = get_list(argc, argv);
// 		swap(stack_a);
// 		while (stack_a != NULL)
// 		{
// 			printf("%d\n", stack_a->data);
// 			stack_a = stack_a->next;
// 		}
// 	}
// }