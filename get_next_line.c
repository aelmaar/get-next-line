/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:13:41 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/19 11:54:53 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	left[INT_MAX];
	size_t		i;
	size_t		j;

	line = read_from_file(fd, left);
	i = 0;
	if (line)
	{
		while (line[i] && line[i] != '\n')
			i++;
		j = 0;
		if (line[i] == '\n')
		{
			while (line[++i])
				left[j++] = line[i];
			left[j] = '\0';
		}
		line[i - j] = '\0';
	}
	return (line);
}
