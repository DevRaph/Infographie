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

# define D_X	0
# define D_Y	0
# define CTE1	0.5 // constante [0,5 ; 1]
# define CTE2	0.5 // constante [0,5 ; 1]

#include <stdio.h>

void		ft_view_up(t_param *p)
{
	t_dlist		*ptr;

	ptr = p->list;
	while (ptr)
	{
		ptr->np.x = (WIN_X - p->x_max * p->sq) / 2 + p->ox; //centrage;
		ptr->np.x += ptr->p.x * p->sq + CTE1; //- D_X * ptr->p.y;
		ptr->np.y = (WIN_Y - p->y_max * p->sq) / 2 + p->oy;
		ptr->np.y += ptr->p.y * p->sq + CTE1 / 2;// + D_Y * ptr->p.x;
		ptr->np.rgb = ft_define_color(p, ptr->p.z);
		ptr = ptr->next;
	}
}

void		ft_view_iso(t_param *p)
{
	t_dlist		*ptr;
	int			np_xmax;
	int			np_ymax;

	ptr = p->list;
	while (ptr)
	{
		//transformation des x
		np_xmax = CTE1 * p->x_max * p->sq - CTE2 * p->y_max * p->sq;
		ptr->np.x = (WIN_X - np_xmax) / 2 + p->ox; //centrage;
		ptr->np.x += CTE1 * ptr->p.x * p->sq - CTE2 * ptr->p.y * p->sq;// - D_X * ptr->p.y;
		// transformation des y
		np_ymax = -(ptr->p.z) * p->h + CTE1 / 2 * p->x_max * p->sq + CTE2 / 2 * p->y_max * p->sq;
		ptr->np.y = (WIN_Y - np_ymax) / 2 + p->oy;
		ptr->np.y += -(ptr->p.z) * p->h + CTE1 / 2 * ptr->p.x * p->sq + CTE2 / 2 * ptr->p.y * p->sq;// + D_Y * ptr->p.x;
		// transformation des z
		//ptr->np.y -= 5 * ptr->p.z;

		ptr->np.rgb = ft_define_color(p, ptr->p.z);
		ptr = ptr->next;
	}
}

void		ft_view_para(t_param *p)
{
	int			d_x;
	t_dlist		*ptr;	
	int			np_xmax;
	int			np_ymax;

	d_x = (p->sq > 1) ? p->sq / 5 : 1;
	ptr = p->list;
	while (ptr)
	{
		ptr->np.x = (WIN_X - p->x_max * p->sq) / 2 + p->ox; //centrage;
		ptr->np.x += ptr->p.x * p->sq + CTE1 * -(ptr->p.z) * p->h;
		ptr->np.y = (WIN_Y - p->y_max * p->sq) / 2 + p->oy;
		ptr->np.y += ptr->p.y * p->sq + CTE1 / 2 * -(ptr->p.z) * p->h;
		ptr->np.rgb = ft_define_color(p, ptr->p.z);
		ptr = ptr->next;
	}
}

void	ft_view(t_param *p)
{
	int		x;
	int		y;

	if (p->reset == 0)
	{
		x = p->x_max / WIN_X;
		y = p->y_max / WIN_Y;
		if (p->x_max * p->sq >= WIN_X || p->y_max * p->sq >= WIN_Y)
		{
			p->sq = (x >= y) ? WIN_X / p->x_max - 1 : WIN_Y / p->y_max - 1;
			//p->sq -= 2;
			p->sq = (p->sq >= 0) ? p->sq : 1;
			p->h  = p->sq / 5;
			p->reset = 1;
			p->rot = 0;
			p->rtt = 0;
		}
	}



	if (p->view == 1)
		ft_view_iso(p);
	else if (p->view == 2)
		ft_view_up(p);
	else if (p->view == 3)
		ft_view_para(p);
	
	/*else
		ft_view_iso(p);*/
}

