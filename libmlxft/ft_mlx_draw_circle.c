/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw_circle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 16:27:28 by igomez            #+#    #+#             */
/*   Updated: 2014/11/29 12:09:49 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft.h"
#include "../fdf.h"
#include <mlx.h>

void	ft_mlx_draw_circle(t_mlxenv *e, t_mlxp p, int r, int opt)
{
	int xy[2];
	int d;

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
