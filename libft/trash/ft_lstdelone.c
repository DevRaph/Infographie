/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 15:55:58 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/03 15:56:02 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include

void	ft_lstdelone(t_list **alst, void (*del)(void *), size_t));
{
	if (*alst)
		(*del)((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
}