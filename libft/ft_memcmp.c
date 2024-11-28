/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:32:50 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 12:32:53 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char str1[] = "Hello, World!";
	const char str2[] = "Hello, World!";
	const char str3[] = "Hello, world!";
	const char str4[] = "Hello, Worl";

	int result1 = ft_memcmp(str1, str2, sizeof(str1));
	printf("Test 1: %s\n", result1 == 0 ? "Identiques" : "Différents");

	int result2 = ft_memcmp(str1, str3, sizeof(str1));
	printf("Test 2: %s\n", result2 == 0 ? "Identiques" : "Différents");

	int result3 = ft_memcmp(str1, str4, sizeof(str4));
	printf("Test 3: %s\n", result3 == 0 ? "Identiques" : "Différents");
}*/