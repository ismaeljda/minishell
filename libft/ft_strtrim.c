/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:38:53 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 13:54:45 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && is_in_set(s1[end], set))
		end--;
	str = (char *)malloc((end - start + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char *result;

	result = ft_strtrim(" . abcd", " ");
	printf("Test 1: '%s'\n", result);

	result = ft_strtrim("hello world", "od");
	printf("Test 2: '%s'\n", result);

	result = ft_strtrim("hello", "xyz");
	printf("Test 3: '%s'\n", result);

	result = ft_strtrim("abcd", "abcd");
	printf("Test 4: '%s'\n", result);

	result = ft_strtrim("", "abc");
	printf("Test 5: '%s'\n", result);

	result = ft_strtrim("hello", "");
	printf("Test 6: '%s'\n", result);

	result = ft_strtrim("remove everything", "remove everything");
	printf("Test 7: '%s'\n", result);

	return (0);
}*/