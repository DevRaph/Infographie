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


void	ft_mlx_draw_square(t_mlxenv *e, t_mlxp pt, t_mlxp p2, int color)
{
	int		x;	
	int		y;

	y = pt.y;
	while (y < (pt.y + p2.y))
	{
		x = pt.x;
		while (x < (pt.x + p2.x))
		{
			mlx_pixel_put(e->mlx, e->win, x, y, color);
			
			x++;
		}
		y++;
	}
}

/*void	ft_mlx_draw_square(t_mlxenv *e, t_mlxp pt, t_mlxp p2, int color)
{
	int		x;	
	int		y;

	y = pt.y;
	while (y < (pt.y + p2.y))
	{
		x = pt.x;
		while (x < (pt.x + p2.x))
		{
			mlx_pixel_put(e->mlx, e->win, x, y, color);
			x++;
		}
		y++;
	}
}
*/

// draw square 1
/*
void	ft_mlx_draw_square(t_mlxenv *e, t_mlxp pt, int p2.x, int p2.y)
{
	int		x;	
	int		y;

	y = pt.y;
	while (y < (pt.y + p2.x))
	{
		x = pt.x;
		while (x < (pt.x + p2.y))
		{
			mlx_pixel_put(e->mlx, e->win, x, y, color);
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
			mlx_pixel_put(e->mlx, e->win, x, y, color);
			x++;
		}
		y++;
	}
}
*/


