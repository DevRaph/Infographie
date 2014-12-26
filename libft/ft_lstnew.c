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



typedef struct		s_dlist
{
	t_mlxp            p;
	t_mlxp            np;
	struct s_dlist    *next;
	struct s_dlist    *down;
}                   t_dlist;

t_dlist		*ft_lstnew(int content, int i, int j)
{
	t_dlist	*ret;

	if (!(ret = (t_dlist *)ft_memalloc(sizeof(t_dlist))))
		return (NULL);
	ret->next = NULL;
	ret->p->z = content;
	ret->p->x = i;
	ret->p->y = j;
	//ret->p->rgb = ft_color() // definir la couleur
	ret->content_size = content_size;
	return (ret);
}

/*
t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;

	if (!(ret = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	ret->next = NULL;
	if (content == NULL)
	{
		ret->content = NULL;
		(*ret).content_size = 0;
		return (ret);
	}
	if ((ret->content = (void *)ft_memalloc(content_size)) == NULL)
		return (NULL);
	ft_memcpy(ret->content, content, content_size);
	ret->content_size = content_size;
	return (ret);
}
*/