/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw_grid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 15:06:51 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/10 15:14:20 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft.h"
#include <mlx.h>

# define PT1 ptr->np
# define PT2 ptr->next->np
# define PT3 ptr->down->np
# define PT4 ptr->down->next->np

/*
static int	ft_maz_side(t_dlist *pt)
{
 return (0);
}


void		ft_fill_square(t_param *s, t_dlist *ptr)
{
	//int		x;	
	int			y;
	t_mlxp		pt1;
	t_mlxp		pt2;

	y = ptr->p.y;
	pt1 = ptr->p;
	pt2 = ptr->next->p;
	while (y < (ptr->p.y + s->sq))
	{
*/		/*x = ptr->p.x;
		while (x < (ptr->p.x + s->sq))
		{
			mlx_pixel_put(e->mlx, e->win, x, y, ft_get_rgb(x - pt.x, 255 - (x - pt.x), 0));
			x++;
		}*/
/*		pt1.y += 1;
		pt2.y += 1;
		ft_mlx_draw_line(&s->e, pt1, pt2, LINE_C_SHD);
		y++;
	}
}

void		ft_mlx_draw_grid(t_param *param)
{
	t_dlist		*ptr;

	ptr = param->list;
	while (ptr != 0)
	{
		if (ptr->next != 0 && ptr->down != 0)
		{
			ft_fill_square(param, ptr);
		}
		ptr = ptr->next;
	}
}
*/

void		ft_mlx_draw_grid(t_param *param)
{
	t_dlist		*ptr;

	ptr = param->list;
	while (ptr != 0)
	{
		if (ptr->next != 0)
		{
			if (ptr->next->p.y == ptr->p.y)
			ft_mlx_draw_line(&param->e, ptr->np, ptr->next->np, LINE_C_SHD);
		}
		if (ptr->down != 0)
			ft_mlx_draw_line(&param->e, ptr->np, ptr->down->np, LINE_C_SHD);
		ptr = ptr->next;
	}
}
