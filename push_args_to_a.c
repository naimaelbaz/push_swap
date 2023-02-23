/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_args_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:29:44 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/22 21:08:12 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_fun(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

t_stack	*check_getlist(int size, char **tmp, t_stack *stack_a)
{
	if ((!check_arg(tmp, size)))
		exit_fun();
	else if (size > 1)
		stack_a = get_list(size, tmp);
	else if (ft_atoi(*tmp) || ft_atoi(*tmp) == 0)
		exit(0);
	// while(1);
	return (stack_a);
}

char	*ft_strcat(char *dst, char *src)
{
	size_t	i;
	size_t	j;
	char	*walo;
	char	*kolchi;

	j = 0;
	i = ft_strlen(dst);
	walo = ft_strtrim(dst, " ");
	kolchi = ft_strtrim(src, " ");
	if (dst[0] == '\0' || src[0] == '\0' || !walo[0] || !kolchi[0])
		exit_fun();
	free(walo);
	free(kolchi);
	dst[i++] = ' ';
	while (src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

t_stack	*check_numberofarg(int size, char **argv, t_stack *stack_a)
{
	char	*str;
	char	**str1;
	char	*result;
	int		size2;
	int		i;

	size2 = 0;
	str = NULL;
	result = NULL;
	if (size >= 2)
	{
		i = 1;
		while (i < size)
		{
			result = ft_strjoin(str, argv[i]);
				//free(str);
			str = ft_strjoin(result, " ");
			// free(result);
			i++;
		}
		//printf("%s\n", str);
		i = 0;
		str1 = ft_split(str, ' ');
		free (str);
		while (str1[i++] != NULL)
			size2++;
		if (size2 == 0)
			exit_fun();
		stack_a = check_getlist(size2, str1, stack_a);
		i = 0;
		while (i < size2)
			free(str1[i++]);
		free(str1);
	}
	return (stack_a);
}


// t_stack	*check_numberofarg(int size, char **argv, t_stack *stack_a)
// {
// 	char	*str;
// 	char	**str1;
// 	int		size2;
// 	int		i;

// 	size2 = 0;
// 	if (size >= 2)
// 	{
// 		i = 1;
// 		str = argv[i];
// 		while (i < size - 1)
// 		{
// 			str = ft_strcat(str, argv[i + 1]);
// 			i++;
// 		}
// 		i = 0;
// 		str1 = ft_split(str, ' ');
// 		while (str1[i++] != NULL)
// 			size2++;
// 		if (size2 == 0)
// 			exit_fun();
// 		stack_a = check_getlist(size2, str1, stack_a);
// 		free(str1);
// 	}
// 	return (stack_a);
// }

