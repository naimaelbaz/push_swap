/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:18:07 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/17 05:43:20 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (!isdigit(str1[i]))
			return (0);
		i++;
	}
	return (1);
}

int	compar(const char *tmp, const char *tmp2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((tmp[i] != '\0' || tmp2[j] != '\0'))
	{
		if (tmp[i] == '+')
			i++;
		if (tmp2[j] == '+')
			j++;
		if (tmp[i] != tmp2[j])
			return (1);
		i++;
		j++;
	}
	return (0);
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
			if (!compar(str1[i], str1[j]))
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

	i = 1;
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

// int	main(int size, char **str1)
// {
// 	t_list			*stack_a;

// 	if (size > 1)
// 	{
// 		//printf("%d",size);
// 		if (!check_arg(str1, size))
// 		{
// 			printf("Error\n");
// 			exit(0);
// 		}
// 		stack_a = get_list(size, str1);
// 		while (stack_a != NULL)
// 		{
// 			printf("%d\n", stack_a->data);
// 			stack_a = stack_a->next;
// 		}
// 	}
// 	return (0);
// }


	// if (size == 2)
	// {
	// 	arg = ft_split(str1[1], ' ');
	// 	while (arg[size] != NULL)
	// 		size++;
	// 	ft_write_lst(stack_a, size, arg, 0);
	// 	free(arg);
	// }