/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 15:01:22 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/27 15:02:38 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft.h"
#include <mlx.h>

// draw grid-point

void	ft_mlx_draw_square(t_mlxenv *e, t_mlxp pt, int side_x, int side_y)
{
	int		x;	
	int		y;

	//sleep(2);
	y = pt.y;
	while (y < (pt.y + side_y))
	{
		x = pt.x;
		while (x < (pt.x + side_x))
		{
			mlx_pixel_put(e->mlx, e->win, x, y, ft_get_rgb(x - pt.x, 255 - (x - pt.x), 0));
			x += 10;
			//usleep(500);
		}
		y += 10;
	}
}


// draw square 1
/*
void	ft_mlx_draw_square(t_mlxenv *e, t_mlxp pt, int side_x, int side_y)
{
	int		x;	
	int		y;

	y = pt.y;
	while (y < (pt.y + side_x))
	{
		x = pt.x;
		while (x < (pt.x + side_y))
		{
			mlx_pixel_put(e->mlx, e->win, x, y, ft_get_rgb(x - pt.x, 0, 255 - (x - pt.x)));
			x++;
		}
		y++;
	}
}
*/

// draw square 2
/*
void	ft_mlx_draw_square(t_mlxenv *e, t_mlxp p1, t_mlxp p2)
{
	int		x;	
	int		y;

	y = p1.y;
	while (y < p2.y)
	{
		x = p1.x;
		while (x < p2.x)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, ft_get_rgb(x - p1.x, 0, 255 - (x - p1.x)));
			x++;
		}
		y++;
	}
}
*/


