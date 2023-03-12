/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:55:08 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/05 20:38:59 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	my_strlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (s && c == '\0')
	{
		while (s[i])
			i++;
	}
	else if (s && c == '\n')
	{
		while (s[i] && s[i] != '\n')
			i++;
	}
	return (i);
}

char	*ft_read(int fd, char *str)
{
	char		*buff;
	int			len;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (free(str), str = NULL, NULL);
	len = 1;
	while (!my_strchr(str, '\n') && len > 0)
	{	
		len = read(fd, buff, BUFFER_SIZE);
		if (len == -1)
		{
			free (buff);
			free(str);
			return (NULL);
		}
		buff[len] = '\0';
		str = my_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*tmp;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (str)
			return (free(str), str = NULL, NULL);
		return (NULL);
	}
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	i = my_strlen(str, '\n');
	line = my_substr(str, 0, i + 1);
	if (!line)
	{
		if (str)
			return (free(str), str = NULL, NULL);
		return (NULL);
	}
	tmp = str;
	str = my_substr(tmp, i + 1, my_strlen(tmp, '\0'));
	return (free(tmp), line);
}
