/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:03:27 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/05 22:26:26 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_mv_2(t_stack **stack_a, t_stack **stack_b, char *mv)
{
	if (ft_strncmp(mv, "sa\n", 2) == 0)
		swap(*stack_a);
	else if (ft_strncmp(mv, "ra\n", 2) == 0)
		rotate(stack_a);
	else if (ft_strncmp(mv, "pa\n", 2) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(mv, "sb\n", 2) == 0)
		swap(*stack_b);
	else if (ft_strncmp(mv, "rb\n", 2) == 0)
		rotate(stack_b);
	else if (ft_strncmp(mv, "pb\n", 2) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp(mv, "rr\n", 2) == 0)
		rotate_ab(stack_a, stack_b);
	else if (ft_strncmp(mv, "ss\n", 2) == 0)
		swap_ab(*stack_a, *stack_b);
	else
		exit_error(*stack_a, *stack_b);
}

void	check_mv_3(t_stack **stack_a, t_stack **stack_b, char *mv)
{
	if (ft_strncmp(mv, "rra", 3) == 0)
		rev_rotate(stack_a);
	else if (ft_strncmp(mv, "rrb", 3) == 0)
		rev_rotate(stack_b);
	else if (ft_strncmp(mv, "rrr", 3) == 0)
		rev_rotate_ab(stack_a, stack_b);
	else
		exit_error(*stack_a, *stack_b);
}

void	check_instr(t_stack **stack_a, t_stack **stack_b)
{
	char	*mv;

	mv = get_next_line(0);
	while (mv)
	{
		if (mv == 0)
			exit(1);
		if (mv[2] == '\n')
			check_mv_2(stack_a, stack_b, mv);
		else if (mv[2] == 'a' || mv[2] == 'b' || mv[2] == 'r')
		{
			check_mv_3(stack_a, stack_b, mv);
			if (mv[3] != '\n')
				exit_error(*stack_a, *stack_b);
		}
		else
			exit_error(*stack_a, *stack_b);
		free(mv);
		mv = get_next_line(0);
	}
	free(mv);
}
