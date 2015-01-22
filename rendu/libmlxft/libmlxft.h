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

# define GET_COLOR_RED		0x10
# define GET_COLOR_BLUE		0x00
# define GET_COLOR_GREEN	0x08
# define RED				0xFF0000
# define GREEN				0x00FF00
# define BLUE				0x0000FF
# define BLACK				0x000000
# define WHITE				0xFFFFFF
# define LINE_C_SRC			0x00
# define LINE_C_DST			0x01
# define LINE_C_MIX			0x02
# define LINE_C_SHD			0x03
# define MIN(a, b)			((a < b) ? a : b)
# define MAX(a, b)			((a > b) ? a : b)
# define ABS(a)				((a >= 0) ? a : -(a))
# define X					0x0
# define Y					0x1
# define WIN_X				1280
# define WIN_Y				1024

typedef struct		s_mlxp
{
	int		x;
	int		y;
	int		z;
	int		rgb;
}					t_mlxp;

typedef struct		s_mlxenv
{
	void	*mlx;
	void	*win;
	void	*img;
}					t_mlxenv;

typedef struct		s_dlist
{
	t_mlxp			p;
	t_mlxp			np;
	struct s_dlist	*next;
	struct s_dlist	*down;
}					t_dlist;

typedef struct		s_param
{
	char			*file;
	int				fd;
	int				x_max;
	int				y_max;
	int				z_max;
	int				z_min;
	int				ox;
	int				oy;
	int				sq;
	int				h;
	int				view;
	int				color;
	int				reset;
	int				nb_color;
	int				xy[2];
	t_mlxenv		e;
	t_dlist			*list;
	t_dlist			*fin;
	int				water;
	int				para;
	int				help;
	int				sl;
	t_mlxp			btm;
	char			*data;
	int				bpp;
	int				endian;
}					t_param;

int					ft_error(char const *s);
void				ft_mlx_draw_square(t_param *p, t_mlxp s, t_mlxp d, int c);
t_mlxp				ft_new_point(int x, int y, int rvb);
void				ft_mlx_draw_line(t_param *s, t_mlxp p, t_mlxp p2, int opt);
void				ft_mlx_draw_circle(t_mlxenv *e, t_mlxp p, int r, int opt);
void				ft_mlx_draw_center(t_mlxenv *e);
int					ft_create_map(t_param *param);
t_dlist				*ft_lstnew(int content, int i, int j);
void				ft_lstprint(t_dlist *my_list);
void				ft_view(t_param *param);
void				ft_mlx_draw_grid(t_param *param);
int					ft_check_grid(char *map);
void				ft_rotate(t_dlist **list, t_param p);
int					ft_define_color(t_param *p, int z);
void				ft_print_param(t_param *p);
void				ft_work(t_param *p, int clear);
int					ft_mouse_hook(int button, int x, int y, t_param *p);
int					ft_key_hook(int k, t_param *p);
int					ft_expose_hook(t_param *p);
void				ft_launch(t_param *p, char *file);
void				ft_init_param(t_param *p, char *file);
void				ft_param_print(char *s, t_param *p);

#endif
