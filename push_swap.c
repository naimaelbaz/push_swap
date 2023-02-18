/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:52:58 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/18 04:32:28 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convert_to_array(t_stack *stack_tmp, int size)
{
	t_stack	*node;
	int		*tab;
	int		i;

	i = 0;
	node = stack_tmp;
	tab = malloc(sizeof(int) * size);
	while (node != NULL && i < size)
	{
		tab[i] = node->data;
		i++;
		node = node->next;
	}
	return (tab);
}

int	main(int argc, char **argv)
{
	t_stack			*stack_a;
	t_stack			*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = check_numberofarg(argc, argv, stack_a);
		stack_b = pb(&stack_a, stack_b, ft_lstsiz(stack_a));
		get_index_args(stack_a, ft_lstsiz(stack_a));
		get_index_args(stack_b, ft_lstsiz(stack_b));
		// printf(">>>>>>>>>>A<<<<<<<<<<\n");
		// print_stack(stack_a);
		// printf(">>>>>>>>>>B<<<<<<<<<<\n");
		// print_stack(stack_b);
		push_to_a(&stack_a, &stack_b);
	}
	exit (0);
}
