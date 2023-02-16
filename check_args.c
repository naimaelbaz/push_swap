/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:18:07 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/13 16:14:09 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_is_integer(char *argv)
{
	int	i;
	int	r;

	i = 0;
	r = 1;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	if (argv[i] == '\0')
		return (0);
	while (argv[i] != '\0')
	{
		if (!isdigit(argv[i]))
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

int	a_duplicate(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (j < argc)
		{
			if (!compar(argv[i], argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_arg(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!a_is_integer(argv[i]))
			return (0);
		i++;
	}
	if (!a_duplicate(argv, argc))
		return (0);
	return (1);
}

// int	main(int argc, char **argv)
// {
// 	t_list			*stack_a;

// 	if (argc > 1)
// 	{
// 		//printf("%d",argc);
// 		if (!check_arg(argv, argc))
// 		{
// 			printf("Error\n");
// 			exit(0);
// 		}
// 		stack_a = get_list(argc, argv);
// 		while (stack_a != NULL)
// 		{
// 			printf("%d\n", stack_a->data);
// 			stack_a = stack_a->next;
// 		}
// 	}
// 	return (0);
// }


	// if (argc == 2)
	// {
	// 	arg = ft_split(argv[1], ' ');
	// 	while (arg[size] != NULL)
	// 		size++;
	// 	ft_write_lst(stack_a, size, arg, 0);
	// 	free(arg);
	// }