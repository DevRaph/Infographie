/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 15:08:25 by rpinet            #+#    #+#             */
/*   Updated: 2014/12/10 12:53:56 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMLXFT_H
# define LIBMLXFT_H

# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define BLACK		0x000000
# define WHITE		0xFFFFFF

# define LINE_C_SRC			0x00
# define LINE_C_DST			0x01
# define LINE_C_MIX			0x02
# define LINE_C_SHD			0x03

# define GET_COLOR_RED		0x10
# define GET_COLOR_BLUE		0x00
# define GET_COLOR_GREEN	0x08

# define MIN(a, b)			((a < b) ? a : b)
# define MAX(a, b)			((a > b) ? a : b)
# define ABS(a)			((a >= 0) ? a : -(a))

# define X 0x0
# define Y 0x1

# define WIN_X		1280
# define WIN_Y		1024

/*
* Point structure
*/
typedef struct		s_mlxp
{
	int		x;
	int		y;
	int		z;
	int		rgb;
}					t_mlxp;

/*
* Envirronement structure
*/
typedef struct		s_mlxenv
{
	void	*mlx;
	void	*win;
	void	*img;
}					t_mlxenv;

/*
* List structure : grid coord and projection point coord
*/
typedef struct		s_dlist
{
	t_mlxp			p;
	t_mlxp			np;
	struct s_dlist	*next;
	struct s_dlist	*down;
}					t_dlist;

/*
* Params structure
*/
typedef struct		s_param
{
	char			*file;
	int				fd;
	int				x_max;
	int				y_max;
	int				z_max;
	int				z_min;
	int				ox;			/* translation in x */
	int				oy;			/* translation in y */
	int				sq;			/* square size */
	int				h;
	int				view;		/* type of view 1, 2 ou 3 */
	int				color;		/* type of coloration */
	int				reset;
	int				nb_color;
	int				xy[2];
	t_mlxenv		e;
	t_dlist			*list;
	int				rot;
	int				rtt;
}					t_param;

void		ft_mlx_draw_square(t_mlxenv * e, t_mlxp pt, int side_x, int side_y);
t_mlxp		ft_new_point(int x, int y, int rvb);
void		ft_mlx_draw_line(t_mlxenv *e, t_mlxp p1, t_mlxp p2, int opt);
//int			ft_get_rgb(int r, int g, int b);
//int			ft_get_color(int rgb, int opt);

void		ft_mlx_draw_circle(t_mlxenv *e, t_mlxp p, int r, int opt);
void		ft_mlx_draw_center(t_mlxenv *e);
int			ft_create_map(t_param *param);

t_dlist		*ft_lstnew(int content, int i, int j);
void		ft_lstprint(t_dlist *my_list);
//void		ft_view_para(t_param *param);
void		ft_view(t_param *param);

void		ft_mlx_draw_grid(t_param *param);
int			ft_check_grid(char *map);
void		ft_launch(t_param *p);
void		ft_rotate(t_dlist **list, t_param p);

int			ft_define_color(t_param *p, int z);

void		ft_print_param(t_param *p);

#endif
