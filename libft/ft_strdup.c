/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:01:14 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/06 18:11:20 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*copy;
	char	*ptr;
	int		size;

	ptr = (char *)s;
	size = 0;
	copy = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	while (ptr[size])
	{
		copy[size] = ptr[size];
		size++;
	}
	copy[size] = '\0';
	return (copy);
}
