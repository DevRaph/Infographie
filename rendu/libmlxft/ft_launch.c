/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 13:00:20 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/15 13:02:00 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "libmlxft.h"
#include <mlx.h>
#include <stdlib.h>

int			ft_error(char const *s)
{
	ft_putendl(s);
	return (0);
}

void		ft_init_param(t_param *p, char *file)
{
	p->file = file;
	p->list = NULL;
	p->nb_color = 29;
	p->sq = 30;
	p->h = 30 / 5 + 1;
	p->view = 1;
	p->color = 1;
	p->reset = 0;
	p->x_max = 0;
	p->y_max = 0;
	p->z_max = 0;
	p->z_min = 0;
	p->water = 1;
	p->ox = 0;
	p->oy = 0;
	p->help = 0;
	p->para = 0;
}

void		ft_launch(t_param *p, char *file)
{
	if ((p->e.mlx = mlx_init()) == NULL)
		exit(ft_error("[Mlx init]: Initialisation impossible"));
	p->e.win = mlx_new_window(p->e.mlx, WIN_X, WIN_Y, p->file);
	p->e.img = mlx_new_image(p->e.mlx, WIN_X, WIN_Y);
	p->data = mlx_get_data_addr(p->e.img, &(p->bpp), &(p->sl), &(p->endian));
	ft_work(p, 0);
	mlx_mouse_hook(p->e.win, &ft_mouse_hook, p);
	mlx_expose_hook(p->e.win, &ft_expose_hook, p);
	mlx_key_hook(p->e.win, &ft_key_hook, p);
	mlx_loop(p->e.mlx);
}

int			ft_check_grid(char *map)
{
	while (*map++)
	{
		if (!ft_isdigit(*map) && *map != ' ' && *map != '\n' &&
			*map != '\t' && *map != '\0' && *map != '-')
		{
			ft_putendl("NO VALID MAP\n");
			return (1);
		}
	}
	return (0);
}
