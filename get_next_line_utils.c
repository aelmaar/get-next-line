/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:13:35 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/19 12:07:32 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*join_strs(char *s1, char *s2)
{
	char	*join;
	size_t	i;

	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	if (join)
	{
		while (s1 && s1[i])
		{
			join[i] = s1[i];
			i++;
		}
		while (s2 && *s2)
			join[i++] = *s2++;
		join[i] = '\0';
	}
	if (ft_strlen(join) == 0)
	{
		free(join);
		return (NULL);
	}
	free(s1);
	return (join);
}

char	*read_from_file(int fd, char *left)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	size_t		i;
	int			r;

	line = NULL;
	line = join_strs(line, left);
	left[0] = 0;
	r = read(fd, buf, BUFFER_SIZE);
	while (r > 0)
	{
		buf[r] = '\0';
		line = join_strs(line, buf);
		i = 0;
		while (buf[i] && buf[i] != '\n')
			i++;
		if (buf[i] == '\n')
			break ;
		i = 0;
		while (buf[i])
			buf[i++] = 0;
		r = read(fd, buf, BUFFER_SIZE);
	}
	return (line);
}
