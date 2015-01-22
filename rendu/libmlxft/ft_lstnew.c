/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 15:25:44 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/03 15:25:48 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../libft/libft.h"
#include "libmlxft.h"

t_mlxp			ft_new_point(int x, int y, int rgb)
{
	t_mlxp		pt;

	pt.x = x;
	pt.y = y;
	pt.rgb = rgb;
	return (pt);
}

t_dlist			*ft_lstnew(int content, int i, int j)
{
	t_dlist		*ret;

	if (!(ret = (t_dlist *)ft_memalloc(sizeof(t_dlist))))
		return (NULL);
	ret->next = NULL;
	ret->down = NULL;
	ret->p.z = content;
	ret->p.x = i;
	ret->p.y = j;
	return (ret);
}

void			ft_lstprint(t_dlist *my_list)
{
	t_dlist		*ptr;
	int			y;

	y = 0;
	ptr = my_list;
	while (ptr != NULL)
	{
		if (y != ptr->p.y)
			ft_putstr("\n");
		y = ptr->p.y;
		ft_putnbr(ptr->p.x);
		ft_putstr("-");
		ft_putnbr(ptr->p.y);
		ft_putstr("-");
		ft_putnbr(ptr->np.z);
		ft_putstr(" ");
		ft_putstr("[");
		if (ptr->next != 0)
			ft_putnbr(ptr->next->p.z);
		ft_putstr("][");
		if (ptr->down != 0)
			ft_putnbr(ptr->down->p.z);
		ft_putstr("]  ");
		ptr = ptr->next;
	}
}
