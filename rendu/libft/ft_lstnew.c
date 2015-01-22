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
#include "libft.h"

t_dlist		*ft_lstnew(int content, int i, int j)
{
	t_dlist	*ret;

	if (!(ret = (t_dlist *)ft_memalloc(sizeof(t_dlist))))
		return (NULL);
	ret->next = NULL;
	ret->p->z = content;
	ret->p->x = i;
	ret->p->y = j;
	ret->content_size = content_size;
	return (ret);
}
