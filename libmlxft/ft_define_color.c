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
#include <stdio.h>

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
	//int			index;
	int			color[40] = {0x0978AB, 0x0978AB, 0x0978AB, 0x79B2DE, 0x79B2DE, 
		0x79B2DE, 0x84B9E3, 0x84B9E3, 0x8DC1EA,  0x8DC1EA, 0x96C9F0, 0x96C9F0, 
		0xA1D2F7, 0xA1D2F7, 0xACDBFB, 0xACDBFB, 0xB9E3FF, 0xB9E3FF, 0xC6ECFF, 
		0xC6ECFF, 0xD8F2FE, 0xACD0A5, 0x94BF8B, 0xA8C68F, 0xBDCC96, 0xD1D7AB, 
		0xE1E4B5, 0xEFEBC0, 0xDED6A3, 0xD3CA9D, 0xCAB982, 0xC3A76B, 0xB9985A, 
		0xAA8753, 0xAC9A7C, 0xBAAE9A, 0xCAC3B8, 0xE0DED8, 0xF5F4F2, 0xF5F4F2};

	mh = (ABS(p->z_max) >= ABS(p->z_min)) ? ABS(p->z_max) : ABS(p->z_min);
	d_h = (float)mh / (39.00 / 2.00);
	//index = (int)(z / d_h) + (40 / 2);
	return (color[(int)((z / d_h) + (40 / 2))]);
	return (0x614400);
}

static int	ft_color_game(t_param *p, int z)
{
	int			mh;
	float		d_h;
	int			index;
	int			color[40] = {0x000D24, 0x000D24, 0x000D24, 0x000D24, 0x00113D, 
		0x00113D, 0x00113D, 0x00113D, 0x00113D, 0x00155C, 0x00155C, 0x00155C, 
		0x003C85, 0x003C85, 0x00074C7, 0x00074C7, 0x00BCEB, 0x00BCEB, 0x00BCEB, 
		0xDBFDFF, 		0xFFD95C, 0xFFF1A3, 0xFFF9A3,
		0x00B36B, 0x30B300, 0x30B300, 0x0E7A00, 0x00612A, 0x064200, 
		0x473A00, 0x4D3C00, 0x614400, 0x6B5000, 0xFFC266, 0xC3A76B, 
		0xFFE8E0, 0xFFF5EB, 0xF7FFF5, 0xFAFDFF, 0xFAFDFF };

	mh = (ABS(p->z_max) >= ABS(p->z_min)) ? ABS(p->z_max) : ABS(p->z_min);
	d_h = (float)mh / (39.00 / 2.00);
	index = (int)(z / d_h) + (40 / 2);
	index = (p->water == 0 && index <= 14) ? 13 : index;
	return (color[index]);
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
