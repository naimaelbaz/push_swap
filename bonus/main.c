/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:26:22 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/27 15:12:43 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	give_res(t_stack *stack_a, t_stack *stack_b)
{
	if (a_is_sorted(stack_a) && b_is_empty(stack_b))
		ft_putstr_fd("OK\n", 1);
	else if (!a_is_sorted(stack_a) || !b_is_empty(stack_b))
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	// char			mv[3];
	// char			var;


	stack_b = NULL;
	stack_a = NULL;
	if (argc > 1)
	{
		stack_a = check_numberofarg(argc, argv, stack_a);

		check_instr(&stack_a, &stack_b);
		// while (read(0, mv, 3))
		// {
		// 	if (mv[2] == '\n')
		// 		check_mv_2(&stack_a, &stack_b, mv);
		// 	else if (mv[2] == 'a' || mv[2] == 'b' || mv[2] == 'r')
		// 	{
		// 		check_mv_3(&stack_a, &stack_b, mv);
		// 		read(0, &var, 1);
		// 		if (var != '\n')
		// 			exit_error(stack_a, stack_b);
		// 	}
		// 	else
		// 		exit_error(stack_a, stack_b);
		// }
		give_res(stack_a, stack_b);
	}
	return (0);
}
