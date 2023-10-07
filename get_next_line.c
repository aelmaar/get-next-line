/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:13:41 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/07 20:14:44 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left;

	if (fd < 0 || fd == 1 || fd == 2)
		return (NULL);
	line = read_from_file(fd, left);
	left = NULL;
	if (line)
	{
		left = slice_newline(line);
	}
	return (line);
}
