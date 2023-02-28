/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:07:09 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/28 13:49:19 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest(t_stack *stack)
{
	int	small;

	small = stack->data;
	stack = stack->next;
	while (stack != NULL)
	{
		if (stack->data < small)
			small = stack->data;
		stack = stack->next;
	}
	return (small);
}

int	is_small(t_stack *a)
{
	int	smallest;
	t_stack	*t;

	smallest = get_smallest(a);
	t = a;
	while (t)
	{
		if (t->data == smallest)
			return (t->position);
		t = t->next;
	}
	return (0);
}

// int	pos_largest(t_stack **a)
// {
// 	t_stack	*s;
// 	t_stack	*t;
// 	int		pos;

// 	if ((*a)->n == get_largest(*a))
// 		return (1);
// 	s = *a;
// 	t = ft_lstlast(*a);
// 	if (t->n == get_largest(*a) || s->n == get_smallest(s))
// 		return (0);
// 	set_pos_largest(s, t, ft_lstsize(*a), &pos);
// 	return (pos);
// }

// int	put_index_a(t_stack **a, t_stack *s, int *arr)
// {
// 	int	size;
// 	int	i;
// 	int	j;

// 	size = ft_lstsize(*a);
// 	if (s->n < arr[0] && s->n > arr[size - 1])
// 		return (0);
// 	i = 0;
// 	j = size - 1;
// 	while (i <= j)
// 	{
// 		if (s->n > arr[i] && s->n < arr[i + 1])
// 			return (i + 1);
// 		if (s->n < arr[j] && s->n > arr[j - 1])
// 			return (j - size);
// 		i++;
// 		j--;
// 	}
// 	return (pos_largest(a));
// }


int	position_of_a(t_stack *stack_a, int data)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*last;

	tmp = stack_a;
	first = stack_a;
	last = lst_last(stack_a);
	if (data < first->data && data > last->data)
		return (0);
	while (tmp != NULL && tmp->next)
	{
		if (data > tmp->data && data < tmp->next->data)
			return (tmp->next->position);
		tmp = tmp->next;
	}
	if (is_langest(stack_a, data))
		return (max_pos_a(stack_a));
	return (is_small(stack_a));
}

int	*number_of_moves(t_stack *stack_a, t_stack *stack_b)
{
	int		*tab;
	int		i;
	t_stack	*tmp;

	tmp = stack_b;
	i = 0;
	tab = malloc(sizeof(int) * ft_lstsiz(stack_b));
	if (!tab)
		return (NULL);
	while (tmp != NULL)
	{
		tab[i] = position_of_a(stack_a, tmp->data);
		tmp = tmp->next;
		i++;
	}
	return (tab);
}
