/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 19:45:07 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/10 12:58:35 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft.h"
#include "../fdf.h"
#include <math.h>
#include <mlx.h>
#include <stdio.h>


# define GET_COLOR(a, b) ft_get_color(a.rgb, (32 - 8 * b))

/*
static void	ft_pixel_put_to_img(int x, int y, int c, t_param *s)
{
	unsigned int	color;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (y >= WIN_Y || x >= WIN_X || y < 0 || x < 0)
		return ;
	color = mlx_get_color_value(s->e.mlx, c);
	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	s->data[(y * s->sl) + (x * (s->bpp / 8))] = b;
	s->data[(y * s->sl) + (x * (s->bpp / 8)) + 1] = g;
	s->data[(y * s->sl) + (x * (s->bpp / 8)) + 2] = r;
}

static void	ft_mlx_draw_line(t_param *s, t_mlxp p, t_mlxp p2, int opt)
{
	float	incxy[5];
	float	xy[5];
	int		col;
	int		l;
	int		i;

	l = (ABS(p2.y - p.y) > ABS(p2.x - p.x)) ? ABS(p2.y - p.y) : ABS(p2.x - p.x);
	incxy[0] = (float)(p2.x - p.x) / (float)l;
	incxy[1] = (float)(p2.y - p.y) / (float)l;
	i = 1;
	while (++i < 5 && (opt & 1))
		incxy[i] = (float)(GET_COLOR(p2, i) - GET_COLOR(p, i)) / (float)l;
	xy[0] = p.x + 0.5;
	xy[1] = p.y + 0.5;
	i = 1;
	while (++i < 5)
		xy[i] = ft_get_color(p.rgb, 32 - 8 * i) + 0.1;
	while (l-- >= 0 && (i = -1))
	{
		col = (s->dgr == 1) ? ft_get_rgb((int)xy[2], (int)xy[3], (int)xy[4]) :
			0xFFFFFF * opt;
		ft_pixel_put_to_img((int)xy[0], (int)xy[1], col, s);
		while (++i < 5 || ((i < 2) && (opt & 1)))
			xy[i] = xy[i] + incxy[i];
	}
}*/


void	ft_mlx_draw_line(t_mlxenv *e, t_mlxp p, t_mlxp p2, int opt)
{
	int		l;
	float	xy[5];
	float	incxy[5];
	int		i;

	l = (abs(p2.y - p.y) > abs(p2.x - p.x)) ? abs(p2.y - p.y) : abs(p2.x - p.x);
	incxy[X] = (float)(p2.x - p.x) / (float)l;
	incxy[Y] = (float)(p2.y - p.y) / (float)l;
	i = 1;
	while (++i < 5)
		incxy[i] = (float)(GET_COLOR(p2, i) - GET_COLOR(p, i)) / (float)l;
	xy[X] = p.x + 0.5;
	xy[Y] = p.y + 0.5;
	i = 1;
	while (++i < 5)
		xy[i] = GET_COLOR(p, i) + 0.1;
	while (l-- >= 0 && (i = -1))
	{
		mlx_pixel_put(e->mlx, e->win, (int)xy[X], (int)xy[Y], ft_get_rgb((int)xy[2], (int)xy[3], (int)xy[4]));
		while (++i < 5)
			xy[i] = xy[i] + incxy[i];
	}
}
