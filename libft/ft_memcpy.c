/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:32:57 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 13:29:06 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src;
	size_t				i;

	if (!dest_str && !src_str)
		return (NULL);
	dest = (unsigned char *)dest_str;
	src = (const unsigned char *)src_str;
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest_str);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "";
	char	dest[50] = "";

	printf("Chaîne source avant memcpy : %s\n", src);
	ft_memcpy(dest, src, 5);
	printf("Chaîne destination après memcpy : %s\n", dest);
	return (0);
}
*/