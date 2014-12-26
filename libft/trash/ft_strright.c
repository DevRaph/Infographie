/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strright.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 15:42:47 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/26 16:18:22 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strright(char const *s, size_t n)
{
	if (s && *s && n <= ft_strlen(s))
		return ((char *)s + ft_strlen(s) - n);
	return ((char *)s);
}
/*
#include "../libft.h"

char	*ft_strright(char const *s, size_t n)
{
	if (!s || !*s || n > ft_strlen(s))
		return ((char *)s);
	return ((char *)s + ft_strlen(s) - n);
}
*/

#include <stdio.h>

int		main(int ac, char **av)
{
	int		i;

	printf ("debut\n");
	while (--ac)
	{
		printf ("boucle d'arguments av[%s]\n", av[ac]);
		i = -1;
		while (++i < 10)
		{
			printf ("%d-[%s]\n", i, ft_strright(av[ac], i));
		}
	}
	return (0);
}
