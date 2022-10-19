/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:07:58 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/19 18:34:21 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left[INT_MAX];

	if (fd < 0)
		return (NULL);
	line = read_from_file(fd, left[fd]);
	left[fd] = NULL;
	if (line)
	{
		left[fd] = check_nl_and_alloc_left(line);
	}
	return (line);
}
