/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:36:53 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 12:36:57 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void) {
	char dest[14];
	const char *src = "Hello, World!";

	size_t result = ft_strlcpy(dest, src, sizeof(dest));

	printf("Chaîne copiée : '%s'\n", dest);
	printf("Taille de la chaîne source : %zu\n", result);

	if (result >= sizeof(dest)) {
		printf("La chaîne source a été tronquée.\n");
	}

	return (0);
}
*/