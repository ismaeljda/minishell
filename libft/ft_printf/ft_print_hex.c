/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:05:58 by isall             #+#    #+#             */
/*   Updated: 2024/11/11 17:53:23 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_number(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_print_hex(unsigned int n)
{
	char	*hex;
	int		len;

	hex = "0123456789abcdef";
	len = len_number(n);
	if (n > 15)
	{
		ft_print_hex(n / 16);
		ft_print_hex(n % 16);
	}
	if (n <= 15)
	{
		n = hex[n];
		ft_putchar(n);
	}
	return (len);
}

int	ft_print_hexx(unsigned int n)
{
	char	*hex;
	int		len;

	hex = "0123456789ABCDEF";
	len = len_number(n);
	if (n > 15)
	{
		ft_print_hexx(n / 16);
		ft_print_hexx(n % 16);
	}
	if (n <= 15)
	{
		n = hex[n];
		ft_putchar(n);
	}
	return (len);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d\n",ft_print_hex(239));
// 	return (0);
// }