/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_args_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:29:44 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/15 22:14:00 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_fun(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

t_stack	*check_getlist(int size, char **tmp, t_stack *stack_a, int a)
{
	if (!check_arg(tmp, size))
		exit_fun();
	stack_a = get_list(size, tmp, a);
	return (stack_a);
}

t_stack	*check_numberofarg(int size, char **argv, t_stack *stack_a)
{
	char	**str;
	int		size2;
	int		i;

	i = 0;
	str = NULL;
	size2 = 0;
	if (size == 2)
	{
		str = ft_split(argv[1], ' ');
		while (str[i++] != NULL)
			size2++;
		if (size2 > 1)
			stack_a = check_getlist(size2, str, stack_a, 0);
		else
			exit(0);
	}
	else if (size >= 3)
		stack_a = check_getlist(size, argv, stack_a, 1);
	return (stack_a);
}
