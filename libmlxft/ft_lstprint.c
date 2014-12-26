/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 16:24:57 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/03 16:24:58 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "libmlxft.h"

void	ft_lstprint(t_dlist *my_list)
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
		ft_putstr("\t");
	/*	ft_putnbr(ptr->np.z);
		ft_putstr(" ");
		ft_putstr("[");
		if (ptr->next != 0)
			ft_putnbr(ptr->next->p.z);
		ft_putstr("][");
		if (ptr->down != 0)
			ft_putnbr(ptr->down->p.z);
		ft_putstr("]  ");*/
		ptr = ptr->next;
	}
	ft_putstr(" fin d'affichage\n");
}
