/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:55:45 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/05 22:19:11 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*my_strdup(char *s1);
size_t	my_strlen(const char *s, char c);
char	*my_strchr(const char *s, int c);
char	*my_strjoin(char *s1, char const *s2);
void	*my_memcpy(void *dest, const void *src, size_t n);
char	*my_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif