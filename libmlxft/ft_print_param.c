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

void	ft_print_param(t_param *p)
{
	mlx_string_put(p->e.mlx, p->e.win, 10, 10, WHITE, ft_strjoin("z_max :", ft_itoa(p->z_max)));
	mlx_string_put(p->e.mlx, p->e.win, 75, 10, WHITE, ft_strjoin("z_max :", ft_itoa(p->z_min)));
	mlx_string_put(p->e.mlx, p->e.win, 150, 10, WHITE, ft_strjoin("z_max :", ft_itoa(p->h)));
}
