/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:18:07 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/12 22:32:14 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	to_pos(int tab)
{
	if (tab < 0)
		tab *= -1;
	return (tab);
}

int	a_is_integer(char *str1)
{
	int	i;

	i = 0;
	if (str1[i] == '-' || str1[i] == '+')
		i++;
	if (str1[i] == '\0')
		return (0);
	while (str1[i] != '\0')
	{
		if (!ft_isdigit(str1[i]))
			return (0);
		i++;
	}
	return (1);
}

int	a_duplicate(char **str1, int size)
{
	int	i;
	int	j;

	i = 0;
	while (str1[i])
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_atoi(str1[i]) == ft_atoi(str1[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_arg(char **str1, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!a_is_integer(str1[i]))
			return (0);
		i++;
	}
	if (!a_duplicate(str1, size))
		return (0);
	return (1);
}
