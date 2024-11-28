/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:36:19 by isall             #+#    #+#             */
/*   Updated: 2024/10/22 16:14:18 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		str[i] = s1[i];
	i--;
	while (++i < len_s1 + len_s2)
		str[i] = s2[i - len_s1];
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char *result;
	result = ft_strjoin("Hello, ", "World!");
	printf("Test 1: %s\n", result);
	free(result);
	result = ft_strjoin("", "World!");
	printf("Test 2: %s\n", result);
	free(result);
	result = ft_strjoin("Hello, ", "");
	printf("Test 3: %s\n", result);
	free(result);
	result = ft_strjoin("", "");
	printf("Test 4: %s\n", result);
	free(result);
	return (0);
}*/