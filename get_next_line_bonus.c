/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:07:58 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/07 20:14:14 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left[INT_MAX];

	if (fd < 0 || fd == 1 || fd == 2)
		return (NULL);
	line = read_from_file(fd, left[fd]);
	left[fd] = NULL;
	if (line)
	{
		left[fd] = slice_newline(line);
	}
	return (line);
}
