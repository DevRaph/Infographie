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

void		ft_init_color(t_param *p)
{
	char	*file;
	char	*line;
	int		fd;
	int		i;

	if (p->color == 3 || p->color == 4)
	{
		file = (p->color >= 4) ? "includes/game.ini" : "includes/carto.ini";
		if ((fd = open(file, O_RDONLY)) <= -1)
			exit(ft_error("[Color]: open() failed"));
		get_next_line(fd, &line);
		if (!(p->col = (int *)malloc(sizeof(int) * ft_atoi_base(line, 10))))
			exit(ft_error("[Color]: malloc failed"));
		p->nb_color = ft_atoi_base(line, 10);
		i = 0;
		while (get_next_line(fd, &line) > 0)
			p->col[i++] = ft_atoi_base(line, 16);
		p->col[i++] = ft_atoi_base(line, 16);
		if (close(fd) == -1)
			exit(ft_error("[Color]: close() failed"));
	}
}

static int	ft_color_carto(t_param *p, int z)
{
	int		mh;
	float	d_h;

	mh = (ABS(p->z_max) >= ABS(p->z_min)) ? ABS(p->z_max) : ABS(p->z_min);
	d_h = (float)mh / (39.00 / 2.00);
	if (z <= p->z_min && mh == 0)
		return (p->col[20]);
	else
		return (p->col[(int)((z / d_h) + (40.00 / 2.00))]);
}

static int	ft_color_game(t_param *p, int z)
{
	int		mh;
	float	d_h;
	int		index;

	mh = (ABS(p->z_max) >= ABS(p->z_min)) ? ABS(p->z_max) : ABS(p->z_min);
	d_h = (float)mh / (40.00 / 2.00);
	index = (z / d_h) + (39.00 / 2.00);
	index = (p->color == 4 && p->water == 0 && index <= 14) ? 13 : index;
	if (z <= p->z_min && mh == 0)
		return (p->col[20]);
	else
		return (p->col[index]);
}

int			ft_define_color(t_param *p, int z)
{
	int		*color;

	if (p->color == 1)
		return (WHITE);
	else if (p->color == 2)
		return (ft_color_height(p, z));
	else if (p->color == 3)
		return (ft_color_carto(p, z));
	else
		return (ft_color_game(p, z));
}
