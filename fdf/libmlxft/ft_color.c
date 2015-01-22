/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 13:11:32 by rpinet            #+#    #+#             */
/*   Updated: 2015/01/06 13:13:08 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft.h"

int			ft_get_color(int rgb, int opt)
{
	return ((rgb >> opt) & 0xFF);
}

int			ft_get_rgb(int r, int g, int b)
{
	return (((r & 0xFF) << 0x10) | ((g & 0xFF) << 0x08) | (b & 0xFF));
}