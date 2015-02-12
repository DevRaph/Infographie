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
#include <stdlib.h>
/*
static void			ft_cut(char **save, char **tmp)
{
	ft_bzero(*save, BUFF_SIZE);
	if (ft_strchr(*tmp, '\n') != NULL)
		*save = ft_strncpy(*save, ft_strchr(*tmp, '\n') + 1, BUFF_SIZE);
	else
		*save = ft_strncpy(*save, ft_strchr(*tmp, '\n'), BUFF_SIZE);
	free(*tmp);
}

static char			*ft_get_line(char *tmp, char end)
{
	size_t			t;
	char			*line;

	t = 0;
	while (tmp[t] != end)
		t++;
	line = (char *)malloc((t + 1) * sizeof(char));
	t = 0;
	while (tmp[t] != end)
	{
		line[t] = tmp[t];
		t++;
	}
	line[t] = '\0';
	return (line);
}

static void			ft_check(char **line, char **tmp, int *ret, char **save)
{
	if (*ret == 0 && ft_strlen(*tmp) > 0)
	{
		*line = *tmp;
		*save += ft_strlen(*save);
		*tmp += ft_strlen(*tmp);
		*ret = 1;
	}
	if (*ret == 0 && ft_strlen(*tmp) == 0)
		*line = NULL;
}

static int			ft_init(char **save, char **buf)
{
	if (!(*buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if (*save == NULL)
	{
		if (!(*save = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
	}
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	static char 	*save;
	char			*tmp;
	int				ret;
	char			*buf;

	if (fd == -1 || line == NULL || (ft_init(&save, &buf) == -1))
			return (-1);
	tmp = ft_strncpy(ft_memalloc(BUFF_SIZE), save, BUFF_SIZE);
	while (!(ft_strchr(tmp, '\n')))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 1)
		{
			ft_check(line, &tmp, &ret, &save);
			if (ret == 0 && ft_strlen(tmp) == 0)
				return (0);
			return (ret);
		}
		buf[ret] = '\0';
		tmp = ft_mallocat(tmp, buf);
	}
	free(buf);
	*line = ft_get_line(tmp, '\n');
	ft_cut(&save, &tmp);
	return (1);
}
*/

typedef struct		s_var
{
	int				ret;
	int				i;
	int				j;
}					t_var;

static int		get_next_line_2(t_var *v, int const fd, char **line)
{
	static char		buf[BUFF_SIZE + 1] = {0};

	while (1)
	{
		v->i = 0;
		while (buf[v->i] && buf[v->i] != '\n')
			v->i++;
		if (v->j == 0 && buf[0] != 0)
			*line = ft_strsub(buf, 0, v->i);
		else if (buf[0] != 0)
			*line = ft_strjoin(*line, ft_strsub(buf, 0, v->i));
		if (buf[v->i] == '\n')
		{
			ft_memcpy(buf, &buf[v->i + 1], BUFF_SIZE - v->i);
			return (1);
		}
		if (buf[v->i] == 0 && v->ret == 0)
			return (0);
		if (buf[0] != 0)
			v->j++;
		if ((v->ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[v->ret] = 0;
	}
	return (0);
}


int			get_next_line(int const fd, char **line)
{
	t_var			v;

	v.j = 0;
	v.ret = 1;
	if (fd < 0)
	{
		ft_putstr("manque le fd, merci CONNARD!\n");
		return (-1);
	}
	return (get_next_line_2(&v, fd, line));
}

