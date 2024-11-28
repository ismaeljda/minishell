/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:38:42 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 14:15:15 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	d;

	d = (unsigned char)c;
	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == d)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%s\n", ft_strrchr("hellolo", 'j'));
	printf("%s\n", strrchr("hellolo", 'j'));

	return (0);
}*/