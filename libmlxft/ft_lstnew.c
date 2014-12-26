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



t_mlxp		ft_new_point(int x, int y, int rgb)
{
	t_mlxp pt;

	pt.x = x;
	pt.y = y;
	pt.rgb = rgb;
	return (pt);
}

t_dlist		*ft_lstnew(int content, int i, int j)
{
	t_dlist	*ret;

	if (!(ret = (t_dlist *)ft_memalloc(sizeof(t_dlist))))
		return (NULL);
	ret->next = NULL;
	ret->down = NULL;
	ret->p.z = content;
	ret->p.x = i;
	ret->p.y = j;
	//ret->p->rgb = ft_color() // definir la couleur
	return (ret);
}
