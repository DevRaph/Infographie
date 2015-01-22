/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:40:45 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/12 16:00:45 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft.h"
#define CTE1 0.5
#define CTE2 0.5
#define SQ p->sq
#define X_M p->x_max
#define Y_M p->y_max
#define XX ptr->p.x
#define YY ptr->p.y

void			ft_view_up(t_param *p)
{
	t_dlist		*ptr;

	ptr = p->list;
	while (ptr)
	{
		ptr->np.x = (WIN_X - X_M * SQ) / 2 + p->ox;
		ptr->np.x += XX * SQ + CTE1;
		ptr->np.y = (WIN_Y - Y_M * SQ) / 2 + p->oy;
		ptr->np.y += YY * SQ + CTE1 / 2;
		ptr->np.rgb = ft_define_color(p, ptr->p.z);
		ptr = ptr->next;
	}
}

void			ft_view_iso(t_param *p)
{
	t_dlist		*ptr;
	int			np_xmax;
	int			np_ymax;
	int			nz;

	ptr = p->list;
	while (ptr)
	{
		nz = (p->water == 0 && ptr->p.z < 0) ? 0 : -(ptr->p.z);
		np_xmax = CTE1 * X_M * SQ - CTE2 * Y_M * SQ;
		ptr->np.x = (WIN_X - np_xmax) / 2 + p->ox;
		ptr->np.x += CTE1 * XX * SQ - CTE2 * YY * SQ;
		np_ymax = nz * p->h + CTE1 / 2 * X_M * SQ + CTE2 / 2 * Y_M * SQ;
		ptr->np.y = (WIN_Y - np_ymax) / 2 + p->oy;
		ptr->np.y += nz * p->h + CTE1 / 2 * XX * SQ + CTE2 / 2 * YY * SQ;
		ptr->np.rgb = ft_define_color(p, ptr->p.z);
		ptr = ptr->next;
	}
}

void			ft_view_para(t_param *p)
{
	int			d_x;
	t_dlist		*ptr;
	int			np_xmax;
	int			np_ymax;
	int			nz;

	d_x = (SQ > 1) ? SQ / 5 : 1;
	ptr = p->list;
	while (ptr)
	{
		nz = (p->water == 0 && ptr->p.z < 0) ? 0 : -(ptr->p.z);
		ptr->np.x = (WIN_X - X_M * SQ) / 2 + p->ox;
		ptr->np.x += XX * SQ + CTE1 * nz * p->h;
		ptr->np.y = (WIN_Y - Y_M * SQ) / 2 + p->oy;
		ptr->np.y += YY * SQ + CTE1 / 2 * nz * p->h;
		ptr->np.rgb = ft_define_color(p, ptr->p.z);
		ptr = ptr->next;
	}
}

void			ft_view(t_param *p)
{
	int			x;
	int			y;

	if (p->reset == 0)
	{
		x = X_M / WIN_X;
		y = Y_M / WIN_Y;
		if (X_M * SQ >= WIN_X || Y_M * SQ >= WIN_Y)
		{
			SQ = 30;
			SQ = (x >= y) ? WIN_X / X_M - 1 : WIN_Y / Y_M - 1;
			SQ = (SQ <= 0) ? 1 : SQ;
			p->h = p->sq / 5 + 1;
			p->reset = 1;
			p->ox = 0;
			p->oy = 0;
		}
	}
	if (p->view == 1)
		ft_view_iso(p);
	else if (p->view == 2)
		ft_view_up(p);
	else if (p->view == 3)
		ft_view_para(p);
}
