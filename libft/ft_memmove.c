/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:33:13 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 15:13:19 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (n == 0 || s1 == s2)
		return (s1);
	dest = (unsigned char *)s1;
	src = (const unsigned char *)s2;
	if (dest < src)
	{
		while (n--)
			*dest++ = *src++;
	}
	else
	{
		dest += n;
		src += n;
		while (n--)
			*(--dest) = *(--src);
	}
	return (s1);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[50] = "Hello, world!";
	char	str2[50] = "Goodbye, world!";

	printf("Avant memmove : str1 = '%s', str2 = '%s'\n", str1, str2);
	// Utiliser ft_memmove pour déplacer les données
	ft_memmove(str1 + 6, str2, 25);
		// Déplace "Hello," dans str1 à partir de l'index 7
	printf("Après memmove : str1 = '%s', str2 = '%s'\n", str1, str2);
	return (0);
}*/