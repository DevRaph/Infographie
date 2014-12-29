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

#include "libmlxft.h"
#include <mlx.h>
#include "../libft/libft.h"

/*
* H of help and P for parameters
*/
static void		ft_para_nul(t_param *p)
{
	char		*str;
	t_mlxp		p1;
	t_mlxp		p2;

	p1.x = 5;
	p1.y = WIN_Y - 25;
	p2.x = 255 ;
	p2.y = p1.y + 25;
	ft_mlx_draw_square(&p->e, p1, p2, 0x000000);
	str = "Press P for parameters and H for help";
	mlx_string_put(p->e.mlx, p->e.win, p1.x + 10 , p1.y + 20, WHITE, str);
}

static void		ft_para_print(t_param *p, t_mlxp p1, t_mlxp p2)
{
	char		*str;

	ft_mlx_draw_square(&p->e, p1, p2, 0x000000);
	str = ft_strjoin("z_max: ", ft_itoa(p->z_max));
	mlx_string_put(p->e.mlx, p->e.win, 10, 20, WHITE, str);
	str = ft_strjoin("z_max: ", ft_itoa(p->z_min));
	mlx_string_put(p->e.mlx, p->e.win, 75, 20, WHITE, str);
	str = ft_strjoin("z_max: ", ft_itoa(p->h));
	mlx_string_put(p->e.mlx, p->e.win, 150, 20, WHITE, str);
}

static void		ft_help_print(t_param *p, t_mlxp p1, t_mlxp p2)
{
	char		*str;

	ft_mlx_draw_square(&p->e, p1, p2, 0x000000);
	str = "zoom + -";
	mlx_string_put(p->e.mlx, p->e.win, p1.x + 5, p1.y + 15, WHITE, str);
	str = "change vue =";
	mlx_string_put(p->e.mlx, p->e.win, p1.x + 5, p1.y + 45, WHITE, str);
	str = "change color .";
	mlx_string_put(p->e.mlx, p->e.win, p1.x + 5, p1.y + 85, WHITE, str);
	str = "move on direction";
	mlx_string_put(p->e.mlx, p->e.win, p1.x + 5, p1.y + 125, WHITE, str);
	str = "reset negative level /";
	mlx_string_put(p->e.mlx, p->e.win, p1.x + 5, p1.y + 165, WHITE, str);
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
		p2.y = 205;
		ft_help_print(p, p1, p2);
	}
}

void		ft_print_param(t_param *p)
{
	t_mlxp		p1;
	t_mlxp		p2;

	p1.x = 5;
	p1.y = 5;
	p2.x = 250;
	p2.y = 20;
	if (!p->help && !p->para)
		ft_para_nul(p);
	else
		ft_print(p, p1, p2);
	//ft_putstr("impression de l'interface\n");
}
