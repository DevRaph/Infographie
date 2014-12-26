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
	t_mlxp		sq;

	ft_mlx_draw_center(&p->e);
	ft_mlx_draw_grid(p);
	return (0);
}

int		ft_key_hook(int k, t_param *p)
{
	printf("key : %d\n", k);
	if (k == 65307)
		exit (0);
	else if (k == 65469) // = pave numerique
		p->view = (p->view >= 3) ? 1 : p->view + 1;
	else if (k == 65454) // . pave numerique
		p->color = (p->color >= 3) ? 1 : p->color + 1;
	else if (k == 65450)
		p->reset = 0;
	else if (k == 65362 || k == 65364) // haut / bas
		p->oy += (k - 65363 > 0) ? 10 : -10;
	else if (k == 65363 || k == 65361) //droite / gauche
		p->ox += (k - 65362 > 0) ? -10 : 10;
	else if ((k == 65453 && p->sq > 1) || k == 65451) // - +
		p->sq += (k - 65452 > 0) ? -1 : 1;
	else if (k == 44 || k == 46) // < et > 
		p->h += (k - 44 == 0) ? 1 : -1;
	if (k == 113 || k == 119 || k == 97 || k == 115 || k == 122 || k == 120)
	{
		p->rot += (k == 97 || k == 113 || k == 122) ? 10 : -10;
		p->rtt = 0 + 2 * (k == 113 || k == 119) + (k == 97 || k == 115);
		printf ("  modif: rot=%d rtt=%d\n", p->rot, p->rtt);
	}
	mlx_clear_window(p->e.mlx, p->e.win);
//ft_rotate(&(p->list), *p);
	ft_view(p); // 1 for iso et 2 for para
	ft_print_param(p);
	//	ft_lstprint(p->list);
	ft_mlx_draw_grid(p);
	return (0);
}

int		ft_mouse_hook(int button, int x, int y, t_param *p)
{
	printf("mouse : %d (%d/%d)\n", button, x, y);
	int static k[2];

	return (0);
}

void	work(t_param *p)
{
	mlx_key_hook(p->e.win, &ft_key_hook, p);
	mlx_expose_hook(p->e.win, &ft_expose_hook, p);
	mlx_mouse_hook(p->e.win, &ft_mouse_hook, p);
	mlx_loop(p->e.mlx);
}


int		main(int ac, char **av)
{
	t_param		p;

ft_launch(&p);
	if (ac == 2 && *av != NULL)
	{
		if ((p.fd = open(av[1], O_RDONLY)) == -1)
		{
			ft_putendl("open() failed");
			return (1);
		}
		if (ft_create_map(&p) == 1)
			return (0);
		if ((p.e.mlx = mlx_init()) == NULL)
		{	
			ft_putendl("[error] Pas d'envirronement");
			return (0);
		}
		p.e.win = mlx_new_window(p.e.mlx, WIN_X, WIN_Y, av[1]);
		ft_view(&p);
		//ft_lstprint(p.list);
		ft_mlx_draw_grid(&p);
		work(&p);
	}
	else if (ac > 2)
		ft_putendl ("[warning] peters : too many files");
	else
		ft_putendl ("[error] give a map in peters");
	return (0);
}
