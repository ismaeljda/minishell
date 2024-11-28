/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:35:06 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 14:13:34 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	d;

	d = (unsigned char)c;
	i = 0;
	while (s[i] || d == '\0')
	{
		if (s[i] == d)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%s\n", ft_strchr("hello", '\0'));
	printf("%s\n", strchr("hello", '\0'));

	return (0);
}*/