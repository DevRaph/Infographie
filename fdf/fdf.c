/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 14:19:18 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/27 14:36:08 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libmlxft/libmlxft.h"
#include "./libft/libft.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>

int		ft_expose_hook(t_param *p)
{
	mlx_put_image_to_window(p->e.mlx, p->e.win, p->e.img, 0, 0);
	ft_print_param(p);
	return (0);
}

#include <stdio.h>
int		ft_key_hook(int k, t_param *p)
{
	//mlx_destroy_image(p->e.mlx, p->e.img);
	if (k == 65307)
		exit(mlx_destroy_window(p->e.mlx, p->e.win));
	else if (k == 65469)
		p->view = (p->view >= 3) ? 1 : p->view + 1;
	else if (k == 65454)
	{
		p->color = (p->color >= 4) ? 1 : p->color + 1;
		ft_init_color(p);
	}
	else if (k == 65450)
		p->reset = 0;
	else if (k == 65455)
		p->water = (p->water > 0) ? 0 : 1;
	else if (k == 112)
		p->para = (p->para > 0) ? 0 : 1;
	else if (k == 104)
		p->help = (p->help > 0) ? 0 : 1;
	else if (k == 65362 || k == 65364)
		p->oy += (k - 65363 > 0) ? 10 * p->sq : -10 * p->sq;
	else if (k == 65363 || k == 65361)
		p->ox += (k - 65362 > 0) ? 10 * p->sq : -10 * p->sq;
	else if ((k == 65453 && p->sq > 1) || k == 65451)
		p->sq += (k - 65452 > 0) ? -1 : 1;
	else if (k == 44 || k == 46)
		p->h += (k - 44 == 0) ? 1 : -1;
	ft_work(p, 1);
	return (0);
}

int		ft_mouse_hook(int button, int x, int y, t_param *p)
{
	mlx_destroy_image(p->e.mlx, p->e.img);
	if (button == 4 || (button == 5 && p->sq > 1))
		p->sq += (button - 4 > 0) ? -1 : 1;
	ft_work(p, 1);
	return (0);
}

void	ft_work(t_param *p, int clear)
{
	if (clear)
	{
		p->e.img = mlx_new_image(p->e.mlx, WIN_X, WIN_Y);
		p->data = mlx_get_data_addr(p->e.img, &p->bpp, &p->sl, &p->endian);
	}
	ft_view(p);
	ft_mlx_draw_grid(p);
	mlx_put_image_to_window(p->e.mlx, p->e.win, p->e.img, 0, 0);
	ft_print_param(p);
}

int		main(int ac, char **av, char **env)
{
	t_param		p;

	ft_init_param(&p, av[1]);
	if (ac == 2 && *av != NULL)
	{
		if ((p.fd = open(av[1], O_RDONLY)) == -1)
			exit(ft_error("[Main]: open() failed"));
		if (env[0] == NULL)
			exit(ft_error("[Main]: Envirronement disabled"));
		if (ft_create_map(&p) == 1)
			return (0);
		ft_launch(&p, av[1]);
	}
	else if (ac > 2)
		ft_putendl ("[Main]: too many arguments");
	else
		ft_putendl ("[Main]: give a map in parameters");
	return (0);
}
