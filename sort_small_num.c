/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 01:30:47 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/24 16:50:24 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort2(t_stack **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		swap_a(*stack_a);
}

void	ft_sort3(t_stack **stack_a)
{
	t_stack	*l;
	t_stack	*f;
	t_stack	*m;

	l = lst_last(*stack_a);
	f = *stack_a;
	m = (*stack_a)->next;
	if (f->data > m->data && m->data < l->data && f->data < l->data)
		swap_a(*stack_a);
	else if (f->data > m->data && m->data > l->data && f->data > l->data)
	{
		swap_a(*stack_a);
		rev_rotate_a(stack_a);
	}
	else if (f->data > m->data && m->data < l->data && f->data > l->data)
		rotate_a(stack_a);
	else if (f->data < m->data && m->data > l->data && f->data < l->data)
	{
		swap_a(*stack_a);
		rotate_a(stack_a);
	}
	else if (f->data < m->data && m->data > l->data && f->data > l->data)
		rev_rotate_a(stack_a);
	free_stack(stack_a);
}

void	ft_sort4(t_stack **stack_a, t_stack **stack_b, int size)
{
	get_finallist(stack_a, size);
	push_b(stack_b, stack_a);
	ft_sort3(stack_a);
	push_a(stack_a, stack_b);
	free_stack(stack_a);
}

void	ft_sort5(t_stack **stack_a, t_stack **stack_b, int size)
{
	get_finallist(stack_a, size);
	push_b(stack_b, stack_a);
	ft_sort4(stack_a, stack_b, size);
	push_a(stack_a, stack_b);
	free_stack(stack_a);
}

void	sort_small_num(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size == 2 && !a_is_sorted(stack_a))
		ft_sort2(&stack_a);
	else if (size == 3 && !a_is_sorted(stack_a))
		ft_sort3(&stack_a);
	else if (size == 4 && !a_is_sorted(stack_a))
		ft_sort4(&stack_a, &stack_b, size);
	else if (size == 5 && !a_is_sorted(stack_a))
		ft_sort5(&stack_a, &stack_b, size);
}
