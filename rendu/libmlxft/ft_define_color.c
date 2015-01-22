/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 18:14:39 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/24 18:18:08 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int	ft_color_height(t_param *p, int z)
{
	int		mh;
	float	i;

	mh = p->z_max - p->z_min;
	i = 255.00 / (float)mh;
	i = ((i * (float)(z - p->z_min)) <= 0) ? 0 : (i * (float)(z - p->z_min));
	if (mh == 0)
		return (ft_get_rgb(50, 50, 50));
	return (ft_get_rgb((int)i, (int)i, (int)i));
}

static int	*ft_init_color(const char *file)
{
	char	*line;
	int		fd;
	int		i;
	int		*tab;

	if ((fd = open(file, O_RDONLY)) <= -1)
		exit(ft_error("[Color]: open() failed"));
	get_next_line(fd, &line);
	if (!(tab = (int *)malloc(sizeof(int) * ft_atoi_base(line, 10))))
		exit(ft_error("[Color]: malloc failed"));
	i = 0;
	while (get_next_line(fd, &line) > 0)
		tab[i++] = ft_atoi_base(line, 16);
	if (close(fd) == -1)
		exit(ft_error("[Color]: close() failed"));
	return (tab);
}

static int	ft_color_carto(t_param *p, int z, int *color)
{
	int		mh;
	float	d_h;

	mh = (ABS(p->z_max) >= ABS(p->z_min)) ? ABS(p->z_max) : ABS(p->z_min);
	d_h = (float)mh / (40.00 / 2.00);
	if (z <= p->z_min && mh == 0)
		return (color[20]);
	else
		return (color[(int)((z / d_h) + (40.00 / 2.00))]);
}

static int	ft_color_game(t_param *p, int z, int *color)
{
	int		mh;
	float	d_h;
	int		index;

	mh = (ABS(p->z_max) >= ABS(p->z_min)) ? ABS(p->z_max) : ABS(p->z_min);
	d_h = (float)mh / (40.00 / 2.00);
	index = (z / d_h) + (40.00 / 2.00);
	index = (p->color == 4 && p->water == 0 && index <= 14) ? 13 : index;
	if (z <= p->z_min && mh == 0)
		return (color[20]);
	else
		return (color[index]);
}

int			ft_define_color(t_param *p, int z)
{
	int		*color;

	if (p->color == 1)
		return (WHITE);
	else if (p->color == 2)
		return (ft_color_height(p, z));
	else if (p->color == 3)
	{
		color = ft_init_color("includes/carto.ini");
		return (ft_color_carto(p, z, color));
	}
	else
	{
		color = ft_init_color("includes/game.ini");
		return (ft_color_game(p, z, color));
	}
}
