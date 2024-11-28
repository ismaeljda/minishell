/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:37:59 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 12:38:05 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void) {
	printf("Test 1: %d\n", ft_strncmp("hello", "hello", 5));
	printf("Test 1 (std): %d\n", strncmp("hello", "hello", 5));

	printf("Test 2: %d\n", ft_strncmp("hello", "hello", 3));
	printf("Test 2 (std): %d\n", strncmp("hello", "hello", 3));

	printf("Test 3: %d\n", ft_strncmp("hello", "world", 5));
	printf("Test 3 (std): %d\n", strncmp("hello", "world", 5));

	printf("Test 4: %d\n", ft_strncmp("hello", "helicopter", 3));
	printf("Test 4 (std): %d\n", strncmp("hello", "helicopter", 3));

	printf("Test 5: %d\n", ft_strncmp("hello", "hell", 5));
	printf("Test 5 (std): %d\n", strncmp("hello", "hell", 5));

	printf("Test 6: %d\n", ft_strncmp("hello", "heLlo", 5));
	printf("Test 6 (std): %d\n", strncmp("hello", "heLlo", 5));

	printf("Test 7: %d\n", ft_strncmp("", "", 0));
	printf("Test 7 (std): %d\n", strncmp("", "", 0));

	printf("Test 8: %d\n", ft_strncmp("", "hello", 5));
	printf("Test 8 (std): %d\n", strncmp("", "hello", 5));

	printf("Test 9: %d\n", ft_strncmp("hello", "", 5));
	printf("Test 9 (std): %d\n", strncmp("hello", "", 5));

	printf("Test 10: %d\n", ft_strncmp("hello", "world", 0));
	printf("Test 10 (std): %d\n", strncmp("hello", "world", 0));

	printf("Test 11: %d\n", ft_strncmp("hello", "hella", 5));
	printf("Test 11 (std): %d\n", strncmp("hello", "hella", 5));

	return (0);
}*/
