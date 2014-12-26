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

/*
	int			color[40] = {0x0978AB, 0x0978AB, 0x0978AB, 0x79B2DE, 0x79B2DE, 
		0x79B2DE, 0x84B9E3, 0x84B9E3, 0x8DC1EA,  0x8DC1EA, 0x96C9F0, 0x96C9F0, 
		0xA1D2F7, 0xA1D2F7, 0xACDBFB, 0xACDBFB, 0xB9E3FF, 0xB9E3FF, 0xC6ECFF, 
		0xD8F2FE, 0xACD0A5, 0x94BF8B, 0xA8C68F, 0xBDCC96, 0xD1D7AB, 0xE1E4B5, 
		0xEFEBC0, 0xE8E1B6, 0xDED6A3, 0xD3CA9D, 0xCAB982, 0xC3A76B, 0xB9985A, 
		0xAA8753, 0xAC9A7C, 0xBAAE9A, 0xCAC3B8, 0xE0DED8, 0xF5F4F2, 0xF5F4F2};
*/
int		ft_get_color(int rgb, int opt)
{
	return ((rgb >> opt) & 0xFF);
}

int		ft_get_rgb(int r, int g, int b)
{
	return (((r & 0xFF) << 0x10) | ((g & 0xFF) << 0x08) | (b & 0xFF));
}

static int	ft_color_carto(t_param *p, int z)
{
	int			mh;
	float		d_h;
	int			index;
	int			color[40] = {0x0978AB, 0x0978AB, 0x0978AB, 0x79B2DE, 0x79B2DE, 
		0x79B2DE, 0x84B9E3, 0x84B9E3, 0x8DC1EA,  0x8DC1EA, 0x96C9F0, 0x96C9F0, 
		0xA1D2F7, 0xA1D2F7, 0xACDBFB, 0xACDBFB, 0xB9E3FF, 0xB9E3FF, 0xC6ECFF, 
		0xC6ECFF, 0xD8F2FE, 0xACD0A5, 0x94BF8B, 0xA8C68F, 0xBDCC96, 0xD1D7AB, 
		0xE1E4B5, 0xEFEBC0, 0xDED6A3, 0xD3CA9D, 0xCAB982, 0xC3A76B, 0xB9985A, 
		0xAA8753, 0xAC9A7C, 0xBAAE9A, 0xCAC3B8, 0xE0DED8, 0xF5F4F2, 0xF5F4F2};

	mh = (ABS(p->z_max) >= ABS(p->z_min)) ? ABS(p->z_max) : ABS(p->z_min);
	d_h = (float)mh / (39.00 / 2.00);
	index = (int)(z / d_h) + (40 / 2);
	return (color[(int)((z / d_h) + (40 / 2))]);
}

static int	ft_color_game(t_param *p, int z)
{
	int			mh;
	float		d_h;
	int			index;
	int			color[40] = {0x183152, 0x183152, 0x183152, 0x183152, 0x183152, 
		0x183152, 0x183152, 0x183152, 0x183152, 0x375D81, 0x375D81, 0x375D81, 0x375D81, 
		0x375D81, 0x375D81,	0xABC8E2, 0xABC8E2, 0xABC8E2, 0xC4D7ED, 0xC4D7ED, 0xE1E6FA,
		0xFFF168, 0xFFEFB6, 
		0xB0CC99, 0xB0CC99, 0x677E52, 0x6B854B, 0x556627, 0x556627, 
		0x663E10, 0x795344, 0x89725B, 0x9E8479, 0xB09F91, 0xC3A76B, 
		0xE0DED8, 0xE0DED8, 0xF7F7F0, 0xF5F4F2 , 0xF5F4F2 };

	mh = (ABS(p->z_max) >= ABS(p->z_min)) ? ABS(p->z_max) : ABS(p->z_min);
	d_h = (float)mh / (39.00 / 2.00);
	index = (int)(z / d_h) + (40 / 2);
	return (color[(int)((z / d_h) + (40 / 2))]);
}

int		ft_define_color(t_param *p, int z)
{
	if (p->color == 1)
		return(WHITE);
	else if (p->color == 2)
		return (ft_color_carto(p, z));
	else
		return (ft_color_game(p, z));
}
