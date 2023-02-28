/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:29:26 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/28 13:05:22 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strchr_int(int *tab, int l, int c)
{
	int	i;

	i = 0;
	while (i < l)
	{
		if (tab[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_lstsiz(t_stack *lst)
{
	int		tmp;
	t_stack	*p;

	tmp = 0;
	p = lst;
	while (p != NULL)
	{
		p = p->next;
		tmp++;
	}
	return (tmp);
}

int	get_len(int *tab, int size)
{
	int	*len_tab;
	int	len;

	len_tab = get_length(tab, size);
	len = max_len(len_tab, size);
	free(len_tab);
	return (len);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int size)
{
	int			*tab;
	int			*lis_tab;
	// t_stack		*stack_tmp;
	int			len;

	tab = convert_to_array(*stack_a, size);
	lis_tab = get_lis(tab, size);
	len = get_len(tab, size);
	while (size-- > 0)
	{
		if ((strchr_int(lis_tab, len, (*stack_a)->data)) == 0)
		{
			// printf("data = %d\n", (*stack_a)->data);
			push_b(stack_b, stack_a);
			// printf("data = %d\n", (*stack_b)->data);
			if ((*stack_b)->data < lis_tab[len / 2])
				rotate_b(stack_b);
		}
		else
			rotate_a(stack_a);
	}
	free(tab);
	free(lis_tab);
}
