/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 12:47:49 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/19 12:55:27 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft.h"
#include <math.h>
#include <string.h>

t_mlxp	ft_rotate_x(t_mlxp pivot, float theta, t_mlxp pt)
{
	float sinus;
	float cosinus;
	float x;
	float y;
	float z;

	sinus = sin(theta);
	cosinus = cos(theta);
	pt.y -= pivot.y;
	pt.z -= pivot.z; 
	y = pt.y * cosinus - pt.z * sinus;
	z = pt.y * sinus + pt.z * cosinus; 
	pt.y = y + pivot.y;
	pt.z = z + pivot.z;
	return (pt);
}

t_mlxp	ft_rotate_y(t_mlxp pivot, float theta, t_mlxp pt)
{
	float sinus;
	float cosinus;
	float x;
	float y;
	float z;

	sinus = sin(theta);
	cosinus = cos(theta);
	pt.x -= pivot.x;
	pt.z -= pivot.z;
	z = pt.z * cosinus - pt.x * sinus;
	x = pt.z * sinus + pt.x * cosinus;
	pt.x = x + pivot.x;
	pt.y = y + pivot.y;
	pt.z = z + pivot.z;
	pt.z = z;
	return (pt);
}
/*
t_mlxp	ft_rotate_z(t_mlxp pivot, float theta, t_mlxp pt, t_param s)
{
	float sinus;
	float cosinus;
	float x;
	float y;
	t_mlxp pt2;

	sinus = sin(theta);
	cosinus = cos(theta);
	pt2.x = pt.x + (s.x_max) / 2;//- pivot.x;
	pt2.y = pt.y + (s.y_max) / 2;//- pivot.y;
	x = pt.x * cosinus - pt.y * sinus;
	y = pt.x * sinus + pt.y * cosinus;
	pt2.x = x - (s.x_max) / 2;//+ pivot.x ;
	pt2.y = y - (s.y_max) / 2;//+ pivot.y ;
	return (pt2);
}
*/

t_mlxp	ft_rotate_z(t_mlxp pivot, float theta, t_mlxp pt, t_param s)
{
	float sinus;
	float cosinus;
	float x;
	float y;
	t_mlxp pt2;

	sinus = sin(theta);
	cosinus = cos(theta);
	pt.x -= (s.x_max / 2);
	pt.y -= (s.y_max / 2);
	x = pt.x * cosinus - pt.y * sinus;
	y = pt.x * sinus + pt.y * cosinus;
	pt.x = x + (s.x_max / 2);//+ pivot.x ;
	pt.y = y + (s.y_max / 2);//+ pivot.y ;
	return (pt2);
}

void	ft_rotate(t_dlist **list, t_param s)
{
	t_dlist *ptr;
	t_mlxp	pivot;

	ptr = *list;
	pivot.x = (WIN_X - s.x_max * s.sq) / 2 ;
	//pivot.x = (WIN_X - s.x_max * s.sq) / 2 + s.ox ;
	pivot.y = (WIN_Y - s.y_max * s.sq) / 2 ;
	//pivot.y = (WIN_Y - s.y_max * s.sq) / 2 + s.oy - (s.y_max * s.sq) / 2;

	//pivot.x = (WIN_X) / 2;
	//pivot.y = (WIN_Y) / 2;
	pivot.z = 0;
	while (ptr != NULL)
	{
		if (!s.rtt)
		{
			//ptr->np = ft_rotate_z(pivot, s.rot * (3.14 / 180), ptr->p, s);
			ptr->np = ft_rotate_z(pivot, s.rot * (3.14 / 180), ptr->p, s);
		}
		else if (s.rtt == 1)
			ptr->np = ft_rotate_x(pivot, s.rot * (3.14 / 180), ptr->p);
		else
			ptr->np = ft_rotate_y(pivot, s.rot * (3.14 / 180), ptr->p);
		ptr = ptr->next;
	}

}