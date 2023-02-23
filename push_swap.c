/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:52:58 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/22 23:15:35 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	a_is_sorted(t_stack	*stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->data > stack_a->next->data)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	*convert_to_array(t_stack *stack_tmp, int size)
{
	t_stack	*node;
	int		*tab;
	int		i;

	i = 0;
	node = stack_tmp;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	while (node != NULL && i < size)
	{
		tab[i] = node->data;
		i++;
		node = node->next;
	}
	return (tab);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	main(int argc, char **argv)
{
	t_stack			*stack_a;
	t_stack			*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = check_numberofarg(argc, argv, stack_a);/* 10 leaks*/
		
		// if (ft_lstsiz(stack_a) < 6)
		// {
		// 	sort_small_num(stack_a, stack_b, ft_lstsiz(stack_a));
		// }
		// else
		// {
			pb(&stack_a, &stack_b, ft_lstsiz(stack_a));/* 11 leaks*/
			
			get_index_args(stack_a, ft_lstsiz(stack_a));
			get_index_args(stack_b, ft_lstsiz(stack_b));
			push_to_a(&stack_a, &stack_b);
			while (stack_a != NULL)
			{
				printf("%d\n", stack_a->data);
				stack_a = stack_a->next;
			}
		// }
	}
	return (0);
}
