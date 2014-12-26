/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw_center.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 12:08:32 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/03 12:09:16 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft.h"
#include "../fdf.h"
#include <mlx.h>

static void	ft_mlx_draw_circle_center(t_mlxenv *e, t_mlxp p, int r, int opt)
{
	int xy[2];
	int d;

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
		ft_mlx_draw_circle_center(e, p, r - 1, opt - 1);
}

void	ft_mlx_draw_center(t_mlxenv *e)
{
	t_mlxp		center;

	center = ft_new_point(WIN_X / 2, WIN_Y / 2, 0xA0A0A0);
	ft_mlx_draw_circle_center(e, center, 5, 5);
	mlx_pixel_put(e->mlx, e->win, center.x, center.y, center.rgb);
	ft_mlx_draw_circle(e, center, 5, 0);
}
