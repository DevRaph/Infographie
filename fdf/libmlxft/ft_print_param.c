/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 17:21:51 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/26 17:28:51 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "libmlxft.h"
#include <mlx.h>

static void		ft_para_nul(t_param *p)
{
	char		*str;
	t_mlxp		p1;
	t_mlxp		p2;

	p1.x = 5;
	p1.y = WIN_Y - 25;
	p2.x = 250;
	p2.y = p1.y + 25;
	ft_mlx_draw_square(p, p1, p2, 0x202020);
	str = "Press P for parameters and H for help";
	mlx_string_put(p->e.mlx, p->e.win, p1.x + 10, p1.y + 20, WHITE, str);
}

static void		ft_para_print(t_param *p, t_mlxp p1, t_mlxp p2)
{
	char		*str;

	ft_mlx_draw_square(p, p1, p2, 0x202020);
	str = ft_strjoin("hauteur: ", ft_itoa(p->h));
	mlx_string_put(p->e.mlx, p->e.win, 10, 20, WHITE, str);
	if (p->view == 1)
		str = "view: isometrique";
	else
		str = (p->view >= 3) ? "view: parallele" : "view: top";
	mlx_string_put(p->e.mlx, p->e.win, 85, 20, WHITE, str);
	if (p->color == 1)
		str = "color mode: basic";
	else if (p->color == 2)
		str = "color mode: height";
	else
		str = (p->view >= 4) ? "color mode: game" : "color mode: carto";
	mlx_string_put(p->e.mlx, p->e.win, 200, 20, WHITE, str);
}

static void		ft_help_print(t_param *p, t_mlxp p1, t_mlxp p2)
{
	char		*str;

	ft_mlx_draw_square(p, p1, p2, 0x202020);
	str = "+ -  zoom";
	mlx_string_put(p->e.mlx, p->e.win, p1.x + 5, p1.y + 15, WHITE, str);
	str = "=    pchange vue";
	mlx_string_put(p->e.mlx, p->e.win, p1.x + 5, p1.y + 35, WHITE, str);
	str = ".    change color";
	mlx_string_put(p->e.mlx, p->e.win, p1.x + 5, p1.y + 55, WHITE, str);
	str = "arrow for direction";
	mlx_string_put(p->e.mlx, p->e.win, p1.x + 5, p1.y + 75, WHITE, str);
	str = "/    reset negative level";
	mlx_string_put(p->e.mlx, p->e.win, p1.x + 5, p1.y + 95, WHITE, str);
	str = "< >  change height";
	mlx_string_put(p->e.mlx, p->e.win, p1.x + 5, p1.y + 115, WHITE, str);
}

static void		ft_print(t_param *p, t_mlxp p1, t_mlxp p2)
{
	if (!p->para || !p->help)
		ft_para_nul(p);
	if (p->para)
		ft_para_print(p, p1, p2);
	if (p->help)
	{
		p1.x = WIN_X - 155;
		p1.y = 5;
		p2.x = p1.x + 50;
		p2.y = 130;
		ft_help_print(p, p1, p2);
	}
}

void			ft_print_param(t_param *p)
{
	t_mlxp		p1;
	t_mlxp		p2;

	p1.x = 5;
	p1.y = 5;
	p2.x = 320;
	p2.y = 20;
	if (!p->help && !p->para)
		ft_para_nul(p);
	else
		ft_print(p, p1, p2);
}
