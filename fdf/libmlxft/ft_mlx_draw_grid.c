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

#define PT1 ptr->np
#define PT2 ptr->next->np
#define PT3 ptr->down->np
#define PT4 ptr->down->next->np

void			ft_mlx_draw_grid(t_param *param)
{
	t_dlist		*ptr;

	ptr = param->list;
	while (ptr != 0)
	{
		if (ptr->next != 0)
		{
			if (ptr->next->p.y == ptr->p.y)
				ft_mlx_draw_line(param, ptr->np, ptr->next->np, LINE_C_SHD);
		}
		if (ptr->down != 0)
			ft_mlx_draw_line(param, ptr->np, ptr->down->np, LINE_C_SHD);
		ptr = ptr->next;
	}
}
