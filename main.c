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
#include "fdf.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int		ft_expose_hook(t_param *p)
{
	mlx_put_image_to_window(p->e.mlx, p->e.win, p->e.img, 0, 0);
	//ft_mlx_draw_center(&p->e);
	return (0);
}

/*
* 65469 : = (numeric pad)
* 65454 : / (numeric pad)
* 65455 : . (numeric pad)
* 65362 / 65364 : haut / bas
* 65363 / 65361 : droite / gauche
* 65453 / 65451 : - / + (numeric pad)
* 44 / 46 : < / > 
*/
int		ft_key_hook(int k, t_param *p)
{
	mlx_destroy_image(p->e.mlx, p->e.img);
	//printf("key : %d\n", k);
	if (k == 65307)
		exit(mlx_destroy_window(p->e.mlx, p->e.win));
	else if (k == 65469)
		p->view = (p->view >= 3) ? 1 : p->view + 1;
	else if (k == 65454)
		{p->color = (p->color >= 3) ? 1 : p->color + 1;
		//printf("couleur: %d\n", p->color);
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
		p->ox += (k - 65362 > 0) ? -10 * p->sq : 10 * p->sq;
	else if ((k == 65453 && p->sq > 1) || k == 65451)
		p->sq += (k - 65452 > 0) ? -1 : 1;
	else if (k == 44 || k == 46)
		p->h += (k - 44 == 0) ? 1 : -1;
	/* if (k == 113 || k == 119 || k == 97 || k == 115 || k == 122 || k == 120)
	* {
	* 	p->rot += (k == 97 || k == 113 || k == 122) ? 10 : -10;
	* 	p->rtt = 0 + 2 * (k == 113 || k == 119) + (k == 97 || k == 115);
	} */
	ft_work(p, 1);
	return (0);
}

int		ft_mouse_hook(int button, int x, int y, t_param *p)
{
	//printf("mouse : %d (%d/%d)\n", button, x, y);
	int static k[2];

	return (0);
}

void	ft_work(t_param *p, int clear)
{

//ft_param_print("\n\nFonction Work", p); 
	if (clear)
	{
		p->e.img = mlx_new_image(p->e.mlx, WIN_X, WIN_Y);
		p->data = mlx_get_data_addr(p->e.img, &p->bpp, &p->sl, &p->endian);
	}
	//mlx_clear_window(p->e.mlx, p->e.win);
	/* ft_rotate(&(p->list), *p); */
	ft_view(p);
	/* ft_lstprint(p->list); */
	ft_mlx_draw_grid(p);
	ft_print_param(p);
	mlx_put_image_to_window(p->e.mlx, p->e.win, p->e.img, 0, 0);
}

int		main(int ac, char **av, char **env)
{
	t_param		p;


	ft_init_param(&p, av[1]);
p.list = NULL;
	if (ac == 2 && *av != NULL)
	{
		if ((p.fd = open(av[1], O_RDONLY)) == -1)
			exit(ft_error("[Main]: open() failed"));
		if (env[0] == NULL)
			exit(ft_error("[Main]: Envirronement disabled"));
		if (ft_create_map(&p) == 1)
			return (0);
		ft_launch(&p, av[1]);
//ft_param_print("\n\nfonction launch REUSSIE", &p);
	}
	else if (ac > 2)
		ft_putendl ("[Main]warning: too many arguments");
	else
		ft_putendl ("[Main]error: give a map in parameters");
	return (0);
}
