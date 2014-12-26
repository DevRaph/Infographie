/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 10:55:15 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/26 14:12:02 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
/*
char	*ft_strrev(char *s)
{
	char	*ptr1;
	char	*ptr2;


	if (!s || ! *s)
		return (s);
	ptr1 = s;
	ptr2 = s;
	ptr2 += ft_strlen(s) - 1;
	printf ("entree de fonction\n");
	while (ptr1 < ptr2 && ptr1)
	{
		printf("boucle while\n");
	printf ("ptr1 = %c ptr2 = %c\n", *ptr1, *ptr2);
		ft_swap(*ptr1 , *ptr2);
		ptr1++;
		ptr2--;
	}
	return (s);
}*/

char	*ft_strrev(char *str)
{
	int		lenght;
	char	temp;
	int		i;

	lenght = ft_strlen(str);
	i = -1;
	while (--lenght > ++i)
	{
		temp = str[lenght];
		str[lenght] = str[i];
		str[i] = temp;
		//ft_swap(str[i], str[lenght]);
	}
	return (str);
}
/*
int main(int argc, char *argv[])
{
	while (--argc)
    {
		printf("%s backwards is ", argv[argc]);
        printf("%s\n", ft_strrev(argv[argc]));
    }
    return (0);
}
*/