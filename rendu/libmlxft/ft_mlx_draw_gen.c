/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw_circle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 16:27:28 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/29 12:09:49 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft.h"
#include <mlx.h>

static void		ft_mlx_draw_c_center(t_mlxenv *e, t_mlxp p, int r, int opt)
{
	int			xy[2];
	int			d;

	xy[X] = 0;
	xy[Y] = r;
	d = r - 1;
	while (xy[Y] >= xy[X])
	{
		mlx_pixel_put(e->mlx, e->win, p.x + xy[X], p.y + xy[Y], 0x404040);
		mlx_pixel_put(e->mlx, e->win, p.x + xy[Y], p.y + xy[X], 0x202020);
		mlx_pixel_put(e->mlx, e->win, p.x - xy[X], p.y + xy[Y], 0x202020);
		mlx_pixel_put(e->mlx, e->win, p.x - xy[Y], p.y + xy[X], 0x404040);
		mlx_pixel_put(e->mlx, e->win, p.x + xy[X], p.y - xy[Y], 0x202020);
		mlx_pixel_put(e->mlx, e->win, p.x + xy[Y], p.y - xy[X], 0x404040);
		mlx_pixel_put(e->mlx, e->win, p.x - xy[X], p.y - xy[Y], 0x404040);
		mlx_pixel_put(e->mlx, e->win, p.x - xy[Y], p.y - xy[X], 0x202020);
		if (d >= (2 * xy[X]))
			d = d - (2 * xy[X]++) - 1;
		else if (d < (2 * (r - xy[Y])))
			d = d + (2 * xy[Y]--) - 1;
		else
			d = d + (2 * (xy[Y]-- - xy[X]++ - 1));
	}
	if (r > 0 && opt > 0)
		ft_mlx_draw_c_center(e, p, r - 1, opt - 1);
}

void			ft_mlx_draw_center(t_mlxenv *e)
{
	t_mlxp		center;

	center = ft_new_point(WIN_X / 2, WIN_Y / 2, 0xA0A0A0);
	ft_mlx_draw_c_center(e, center, 5, 5);
	mlx_pixel_put(e->mlx, e->win, center.x, center.y, center.rgb);
	ft_mlx_draw_circle(e, center, 5, 0);
}

void			ft_mlx_draw_circle(t_mlxenv *e, t_mlxp p, int r, int opt)
{
	int			xy[2];
	int			d;

	xy[X] = 0;
	xy[Y] = r;
	d = r - 1;
	while (xy[Y] >= xy[X])
	{
		mlx_pixel_put(e->mlx, e->win, p.x + xy[X], p.y + xy[Y], p.rgb);
		mlx_pixel_put(e->mlx, e->win, p.x + xy[Y], p.y + xy[X], p.rgb);
		mlx_pixel_put(e->mlx, e->win, p.x - xy[X], p.y + xy[Y], p.rgb);
		mlx_pixel_put(e->mlx, e->win, p.x - xy[Y], p.y + xy[X], p.rgb);
		mlx_pixel_put(e->mlx, e->win, p.x + xy[X], p.y - xy[Y], p.rgb);
		mlx_pixel_put(e->mlx, e->win, p.x + xy[Y], p.y - xy[X], p.rgb);
		mlx_pixel_put(e->mlx, e->win, p.x - xy[X], p.y - xy[Y], p.rgb);
		mlx_pixel_put(e->mlx, e->win, p.x - xy[Y], p.y - xy[X], p.rgb);
		if (d >= (2 * xy[X]))
			d = d - (2 * xy[X]++) - 1;
		else if (d < (2 * (r - xy[Y])))
			d = d + (2 * xy[Y]--) - 1;
		else
			d = d + (2 * (xy[Y]-- - xy[X]++ - 1));
	}
	if (r > 0 && opt > 0)
		ft_mlx_draw_circle(e, p, r - 1, opt - 1);
}

void			ft_mlx_draw_square(t_param *s, t_mlxp pt, t_mlxp p2, int color)
{
	int			x;
	int			y;

	y = pt.y;
	while (y < (pt.y + p2.y))
	{
		x = pt.x;
		while (x < (pt.x + p2.x))
		{
			mlx_pixel_put(s->e.mlx, s->e.win, x, y, color);
			x++;
		}
		y++;
	}
}
