/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:33:40 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 12:33:44 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	value;

	p = (unsigned char *)str;
	i = 0;
	value = (unsigned char)c;
	while (i < n)
	{
		p[i] = value;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[50] = "he";

	printf("Avant memset : %s\n", str);
	ft_memset(str, '*', 3);
	printf("Après memset : %s\n", str);
	return (0);
}
*/