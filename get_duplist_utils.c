/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_duplist_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:16:03 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/07 12:47:33 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	have_min_number(t_stack *stack_a)
{
	int			min;
	t_stack		*stack;

	min = stack_a->data;
	stack = stack_a->next;
	while (stack != NULL)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

int	get_position(t_stack *stack_a)
{
	int			min;
	int			i;
	t_stack		*stack;

	min = have_min_number(stack_a);
	i = 0;
	stack = stack_a;
	while (stack != NULL)
	{
		if (stack->data == min)
			break ;
		i++;
		stack = stack->next;
	}
	return (i);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

	ptr = *lst;
	if (!ptr)
	{
		*lst = new;
		return ;
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
}

t_stack	*get_newlist(t_stack *stack_tmp, int size)
{
	int			pos;
	int			min;

	pos = get_position(stack_tmp);
	min = have_min_number(stack_tmp);
	while (stack_tmp->data != min)
	{
		if (pos <= (size / 2))
			rotate_a_tmp(&stack_tmp);
		else if (pos > (size / 2))
			rev_rotate_a_tmp(&stack_tmp);
	}
	return (stack_tmp);
}

t_stack	*copy_list(t_stack *stack_a)
{
	t_stack		*tmp;
	t_stack		*str;
	t_stack		*new;

	str = stack_a;
	tmp = newlist(str->data);
	str = str->next;
	while (str != NULL)
	{
		new = newlist(str->data);
		lstadd_back(&tmp, new);
		str = str->next;
	}
	return (tmp);
}