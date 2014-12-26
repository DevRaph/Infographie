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
#include <string.h>
/*
t_list_test    *ft_lstrev(t_list_test **list)
{
    t_list_test    *cur_elem;
    t_list_test    *prev_elem;
    t_list_test    *next_elem;

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
*/

static void        ft_rev(t_lst **head_ref)
{
    t_lst *prev;
    t_lst *current;
    t_lst *next;

    prev = NULL;
    current = *head_ref;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}