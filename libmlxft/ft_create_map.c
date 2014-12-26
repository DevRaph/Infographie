/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 14:20:39 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/03 14:23:52 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "libmlxft.h"
#include <unistd.h>

static void		ft_rev(t_dlist **head_ref)
{
	t_dlist		*prev;
	t_dlist		*current;
	t_dlist		*next;

	prev = NULL;
	current = *head_ref;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

static t_dlist	*ft_link(t_dlist *list)
{
	t_dlist		*ptr;
	t_dlist		*down;

	ptr = list;
	while (ptr != 0)
	{
		down = ptr;
		while (down != 0 && down->p.y <= ptr->p.y + 1)
		{
			if (down->p.x == ptr->p.x && down->p.y == ptr->p.y + 1)
			{
				ptr->down = down;
				break ;
			}
			down = down->next;
		}
		ptr = ptr->next;
	}
	return (list);
}

static void     ft_fill_list(char *pt, t_param *param)
{
	t_dlist     *point;
	point = ft_lstnew(ft_atoi(pt), param->xy[0], param->xy[1]);
	point->next = param->list;
	param->list = point;
	if (ft_atoi(pt) > param->z_max)
		param->z_max = ft_atoi(pt);
	if (ft_atoi(pt) < param->z_min)
		param->z_min = ft_atoi(pt);

	if (param->xy[0] > param->x_max)
	param->x_max = param->xy[0];

	if (param->xy[1] > param->y_max)
		param->y_max = param->xy[1];
}




#include <stdio.h>
/* the integer tab xy[] is fill with x coord in 0, y coord in 1,
x maximum in 2, maximun y in 3*/
int				ft_create_map(t_param *param)
{
	char		**tab;
	char		*map;

	param->xy[1] = 0;
	while (get_next_line(param->fd, &map) > 0)
	{
		if (ft_check_grid(map) != 0)
			return (1);
		tab = ft_strsplit(map, ' ');
		param->xy[0] = -1;
		while (tab[++(param->xy[0])])
		{
			//printf ("x%d x_max%d\n", param->xy[0], param->x_max);
			ft_fill_list(tab[param->xy[0]], param);
		}
		param->xy[1]++;
	}
	if (close(param->fd) == -1)
		ft_putstr("close() failed\n");
	ft_rev(&(param->list));
	param->list = ft_link(param->list);
	return (0);
}
