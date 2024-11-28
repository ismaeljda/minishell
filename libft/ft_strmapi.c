/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:37:15 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 12:37:52 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*str;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include "libft.h"
#include <stdio.h>

char	example_func(unsigned int index, char c)
{
	return (c + index);
}


int	main(void)
{
	char	*result;

	result = ft_strmapi("hello", example_func);
	// Imprime simplement le résultat
	if (result)
	{
		printf("%s\n", result);
		free(result); // N'oubliez pas de libérer la mémoire allouée
	}
	return (0);
}
*/