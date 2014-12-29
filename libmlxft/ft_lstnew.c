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



#include <stdio.h>
void	ft_param_print(char *s, t_param *p)
{
	printf ("%s\n", s);
	printf ("debug param:\n file[%s] fd[%d] nb_color[%d] sq[%d] h[%d]", p->file, p->fd, p->nb_color, p->sq, p->h);
	printf ("\n\tview[%d] color[%d] reset[%d]",p->view, p->color, p->reset);
	printf ("\n\tx_max[%d] y_max[%d] z_max[%d] z_min[%d] rot[%d] rtt[%d]",p->x_max, p->y_max, p->z_max, p->z_min, p->rot, p->rtt);
	printf ("\n\tox[%d] oy[%d] help[%d] para[%d] water[%d]", p->ox, p->oy, p->help, p->para, p->water);
	printf ("\n\tsl[%d] bpp[%d] endian[%d]", p->sl, p->bpp, p->endian);
	// ajout des x y de btm   dans les images
}