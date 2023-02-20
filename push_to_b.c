/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:29:26 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/20 02:39:25 by nel-baz          ###   ########.fr       */
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

/*check_size => check if the most elements of LIS in the top or bottom
of stack_a 
->if in the top do rra 
->if in the bottom do ra*/
int	check_size(t_stack *stack_a, int *tab_lis, int *tab, int size)
{
	int			i;
	int			*array;
	int			len;
	int			*len_tab;
	int			r;

	r = 0;
	i = 0;
	array = convert_to_array(stack_a, size);
	len_tab = get_length(tab, size);
	len = max_len(len_tab, size);
	while (i < size)
	{
		if ((strchr_int(array, size / 2, tab_lis[i])))
			r++;
		i++;
	}
	if (r >= len / 2)
		return (1);
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

int	get_len(t_stack *stack_a, int *tab, int size)
{
	int	*array;
	int	*len_tab;
	int	len;

	array = convert_to_array(stack_a, size);
	len_tab = get_length(tab, size);
	len = max_len(len_tab, size);
	return (len);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int size)
{
	int			*tab;
	int			*lis_tab;
	t_stack		*stack_tmp;
	int			l;
	int			len;
	int			mid;
	
	stack_tmp = get_duplist(*stack_a, size);
	tab = convert_to_array(stack_tmp, size);
	len = get_len(*stack_a, tab, size);
	lis_tab = get_lis(tab, size);
	l = ft_lstsiz(*stack_a) - len;
	mid = mid_value(*stack_a);
	while (ft_lstsiz(*stack_b) < l)
	{
		if ((strchr_int(lis_tab, len, (*stack_a)->data)) == 0)
		{
			push_b(stack_b, stack_a);
			if ((*stack_b)->data < mid)
				rotate_b(stack_b);
		}
		else
			rotate_a(stack_a);
	}
}
