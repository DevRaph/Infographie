/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 13:00:20 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/15 13:02:00 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "libmlxft.h"
#include <string.h>

void	ft_launch(t_param *p)
{
	p->list = NULL;
	p->nb_color = 29;
	p->sq = 30;
	p->h = 6;
	p->view = 1;
	p->color = 3;
	p->reset = 0;
	p->x_max = 0;
	p->y_max = 0;
	p->z_max = 0;
	p->z_min = 0;
	p->rot = 0;
	p->rtt = 0;
	/* value for translate grid in x and y*/
	p->ox = 0;
	p->oy = 0;
}

int		ft_check_grid(char *map)
{
	while (*map++)
	{
		if (!ft_isdigit(*map) && *map != ' ' && *map != '\n' && 
			*map != '\t' && *map != '\0' && *map != '-')
		{
			ft_putendl("NO VALID MAP\n");
			return (1);	
		}
	}
	return (0);
}
