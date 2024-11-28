/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:36:38 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 13:35:53 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	i = 0;
	j = dest_len;
	if (size <= dest_len)
		return (size + src_len);
	while (j < size - 1 && src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dest_len + src_len);
}
/*
#include <stdio.h>

int	main(void) {
	char dest[10] = "Hello, ";
	const char *src = "World!";
	size_t result = ft_strlcat(dest, src, 3);

	printf("Chaîne résultante : '%s'\n", dest);
	printf("Longueur totale : %zu\n", result);


	return (0);
}*/