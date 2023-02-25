/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:26:22 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/26 00:01:48 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	char			mv[3];

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = check_numberofarg(argc, argv, stack_a);
		while (read(0, mv, 3))
		{
			if (mv[2] == '\n')
				check_mv_2(&stack_a, &stack_b, mv);
			else if (mv[2] == 'a' || mv[2] == 'b' || mv[2] == 'r')
				check_mv_3(&stack_a, &stack_b, mv);
			else
				exit_error(stack_a, stack_b);
		}
		if (a_is_sorted(stack_a) && b_is_empty(stack_b))
			ft_putstr_fd("OK\n", 1);
		else if (!a_is_sorted(stack_a) || !b_is_empty(stack_b))
			ft_putstr_fd("KO\n", 1);
	}
	return (0);
}

void	check_mv_2(t_stack **stack_a, t_stack **stack_b, char *mv)
{
	if (ft_strncmp(mv, "sa\n", 2) == 0)
		swap_a(*stack_a);
	else if (ft_strncmp(mv, "ra\n", 2) == 0)
		rotate_a(stack_a);
	else if (ft_strncmp(mv, "pa\n", 2) == 0)
		push_a(stack_a, stack_b);
	else if (ft_strncmp(mv, "sb\n", 2) == 0)
		swap_b(*stack_b);
	else if (ft_strncmp(mv, "rb\n", 2) == 0)
		rotate_b(stack_b);
	else if (ft_strncmp(mv, "pb\n", 2) == 0)
		push_b(stack_b, stack_a);
	else if (ft_strncmp(mv, "rr\n", 2) == 0)
		rotate_ab(stack_a, stack_b);
}

void	check_mv_3(t_stack **stack_a, t_stack **stack_b, char *mv)
{
	if (ft_strncmp(mv, "rra\n", 3) == 0)
		rev_rotate_a(stack_a);
	else if (ft_strncmp(mv, "rrb\n", 3) == 0)
		rev_rotate_b(stack_b);
	else if (ft_strncmp(mv, "rrr\n", 3) == 0)
		rev_rotate_ab(stack_a, stack_b);
}
