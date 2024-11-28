/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:38:16 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 14:22:36 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	str2_len;

	if (*str2 == '\0')
		return ((char *)str1);
	if (len == 0)
		return (NULL);
	str2_len = ft_strlen(str2);
	i = 0;
	while (i < len && str1[i])
	{
		if (i + str2_len > len)
			return (NULL);
		j = 0;
		while (j < str2_len && (i + j) < len && str1[i + j] == str2[j])
		{
			j++;
		}
		if (j == str2_len)
			return ((char *)&str1[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	// Cas de base
	printf("Test 1: %s\n", ft_strnstr("hello world", "llo", 4));
		// Devrait retourner NULL
	printf("Test 2: %s\n", ft_strnstr("hello world", "l", 4));
		// Devrait retourner "lo world"
	printf("Test 3: %s\n", ft_strnstr("hello world", "hello", 11));
		// Devrait retourner "hello world"
	printf("Test 4: %s\n", ft_strnstr("hello world", "world", 11));
		// Devrait retourner "world"
	// Cas avec str2 vide
	printf("Test 5: %s\n", ft_strnstr("hello world", "", 4));
		// Devrait retourner "hello world"
	// Cas avec str1 vide
	printf("Test 6: %s\n", ft_strnstr("", "hello", 4));
		// Devrait retourner NULL
	// Cas avec une longueur nulle
	printf("Test 7: %s\n", ft_strnstr("hello world", "l", 0));
		// Devrait retourner NULL
	// Cas où str2 est plus long que len
	printf("Test 8: %s\n", ft_strnstr("hello world", "hello world", 5));
		// Devrait retourner NULL
	// Cas avec la chaîne str1 égale à str2
	printf("Test 9: %s\n", ft_strnstr("hello world", "hello world", 11));
		// Devrait retourner "hello world"
	// Cas où str2 est à la fin de str1
	printf("Test 10: %s\n", ft_strnstr("hello world", "world", 11));
		// Devrait retourner "world"
	// Cas avec str1 plus court que len
	printf("Test 11: %s\n", ft_strnstr("hi", "hi", 5));
		// Devrait retourner "hi"
	// Cas avec str1 et str2 identiques
	printf("Test 12: %s\n", ft_strnstr("same", "same", 4));
		// Devrait retourner "same"
	return (0);
}
*/