/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:16:48 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 11:19:55 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	res;

	i = 0;
	signe = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (signe * res);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Test 1: %d\n", ft_atoi("123"));        
	printf("Test 4: %d\n", ft_atoi("  42"));        
	printf("Test 5: %d\n", ft_atoi("   -42"));      
	printf("Test 6: %d\n", ft_atoi("+42"));        
	printf("Test 7: %d\n", ft_atoi("42abc"));       
	printf("Test 8: %d\n", ft_atoi("abc42"));    
	printf("Test 9: %d\n", ft_atoi("2147483647"));  
	printf("Test 10: %d\n", ft_atoi("-2147483648")); 

	return 0;
}
*/
