/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strleft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 14:49:21 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/26 15:41:45 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strleft(char const *s, size_t n)
{
	return (ft_strndup(s, n));
}
/*
#include <stdio.h>

int		main(int ac, char **av)
{
	int		i;

	printf ("debut\n");
	while (--ac)
	{
		printf ("boucle d'arguments\n");
		i = -1;
		while (++i < 10)
		{
			printf ("%d-[%s]\n", i, ft_strleft(av[ac], i));
		}
	}
	return (0);
}

*/