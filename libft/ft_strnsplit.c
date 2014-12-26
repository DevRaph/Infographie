/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 17:02:48 by rpinet            #+#    #+#             */
/*   Updated: 2014/11/26 17:12:03 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_count_word(char const *s, char const *c)
{
	int		count;
	int		valid;
	int		tmp;

	valid = 0;
	count = 0;

	while (*s)
	{
		tmp = ft_strncmp(s, c, (size_t)ft_strlen(c));
		if (tmp != 0 && valid == 0)
		{
			count++;
			valid = 1;
		}
		if (tmp == 0 && valid == 1)
			valid = 0;
		s++;
	}
	return (count);
}

size_t	ft_size_word(char const *s, char c)
{
	size_t		size;

	size = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		size++;
	}
	return (size);
}

char	**ft_strsnplit(char const *s, char *pat)
{
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(*tab) * (ft_count_word(s, pat) + 1))))
		return (NULL);
	i = 0;
	while (s && *s)
	{
		if (ft_strncmp(s, pat, (size_t)ft_strlen(pat)) != 0)
		{
			tab[i] = ft_strndup(s, ft_size_word(s, pat));
			//tab[i] = ft_strndup(s, ft_size_word(s, pat) - 1);
			s += ft_size_word(s, pat);
			i++;
		}
		else
			s += ft_strlen(pat);
	}
	tab[i] = '\0';
	return (tab);
}


/*  faire les test pour verifier que ca marche */

#include <stdio.h>

int		main(void)
{
	char	**tab;
//	char 	*test;
//	char	*pattern;
	int		i;

//	test = ft_strdup("bon on va tester ce que ce morceau de chaine\npeux donner avec ce code");
//	pattern = ft_strdup("ce");
	tab = ft_strnsplit("bon on va tester ce que ce morceau de chaine\npeux donner avec ce code", "ce");
	i = 0;
	//printf ("la chaine :\n%s\n", test);
	//printf ("le motif :\n%s\n", pattern);
	printf ("le tableau :\n");
	while (tab[i] != '\0')
	{
		printf ("i=%d - %s\n", i, tab[i]);
		i++;
	}
	return (0); 
}

/*
gcc -Wall -Werror -Wextra ft_strnsplit.c ft_strdup.c ft_strlen.c ft_strndup.c ft_strncmp.c
ft_strnsplit.c: In function 'main':
ft_strnsplit.c:91:2: error: implicit declaration of function 'ft_strnsplit' [-Werror=implicit-function-declaration]
  tab = ft_strnsplit((char const *)test, pattern);
  ^
ft_strnsplit.c:91:6: error: assignment makes pointer from integer without a cast [-Werror]
  tab = ft_strnsplit((char const *)test, pattern);
      ^
cc1: all warnings being treated as errors
*/