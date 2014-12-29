/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 16:18:31 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/29 20:52:44 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int		get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*ptr;
	static char	*stat;
	int			ret;

	while ((!ft_strchr(stat, 10)) && line)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 1)
			break ;
		buf[ret] = '\0';
		stat = (stat == '\0') ? ft_strdup(buf) : ft_strjoin(stat, buf);
	}
	if ((ptr = ft_strchr(stat, 10)) && line)
	{
		*line = stat;
		stat = ptr + 1;
		*ptr = '\0';
		return (1);
	}
	if (stat != '\0' && line)
	{
		*line = stat;
		stat = '\0';
	}
	return ((!line) ? -1 : ret);
}
