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

#define PT1 ptr->p
#define PT2 ptr->next->p
#define PT3 ptr->down->p
#define PT4 ptr->down->next->p
#define PT5	ptr->down->next->np
#define	DN ptr->down->next

void			ft_mlx_draw_grid(t_param *param)
{
	t_dlist		*ptr;

	ptr = param->list;
	while (ptr != 0)
	{
		ft_pixel_put_to_img(ptr->np.x, ptr->np.y, ptr->np.rgb, param);
		if (ptr->next != 0)
		{
			if (ptr->next->p.y == ptr->p.y)
				ft_mlx_draw_line(param, ptr->np, ptr->next->np, LINE_C_SHD);
		}
		if (ptr->down != 0)
			ft_mlx_draw_line(param, ptr->np, ptr->down->np, LINE_C_SHD);
		if (param->color != 1 && ptr->next != 0 && ptr->down != 0 && DN != 0)
		{
			if ((PT2.x == PT4.x) && (PT3.y == PT4.y))
				ft_mlx_draw_line(param, ptr->np, PT5, LINE_C_SHD);
		}
		ptr = ptr->next;
	}
}
