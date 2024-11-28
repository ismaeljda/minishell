/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:23:01 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 16:00:46 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num == 0 || size == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	ptr = malloc(num * size);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, num * size);
	return (ptr);
}

/*
   si num = 0 et size = 0 on doit retourner un pointeur qu'on va pouvoir free
   num = Nombre d'élements
   size = taille de chaque élements
   */
