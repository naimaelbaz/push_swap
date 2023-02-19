/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:54:22 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/18 22:56:51 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*newlist(int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

t_stack	*get_list(int size_list, char **data)
{
	t_stack	*new;
	t_stack	*next_node;
	t_stack	*tmp;
	int		i;

	i = 0;
	new = newlist(ft_atoi(data[i++]));
	tmp = new;
	while (i < size_list)
	{
		next_node = malloc(sizeof(t_stack));
		if (!next_node)
			return (NULL);
		next_node->data = ft_atoi(data[i]);
		next_node->next = NULL;
		tmp->next = next_node;
		tmp = next_node;
		i++;
	}
	return (new);
}
