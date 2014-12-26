/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 16:24:19 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/03 16:24:24 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist    *ft_lstrev(t_dlist **list)
{
    t_dlist    *cur_elem;
    t_dlist    *prev_elem;
    t_dlist    *next_elem;

    cur_elem = *list;
    prev_elem = NULL;
    next_elem = NULL;
    while (cur_elem !=  NULL)
    {
        *list = cur_elem;
        prev_elem = cur_elem->next;
        cur_elem->next = next_elem;
        next_elem = cur_elem;
        cur_elem = prev_elem;
    }
    return (prev_elem);
}
