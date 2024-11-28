/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:06:33 by isall             #+#    #+#             */
/*   Updated: 2024/10/15 09:34:04 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_number(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static int	ft_print_hexa(unsigned long long n)
{
	char	*hex;
	int		len;

	hex = "0123456789abcdef";
	len = len_number(n);
	if (n > 15)
	{
		ft_print_hexa(n / 16);
		ft_print_hexa(n % 16);
	}
	if (n <= 15)
	{
		n = hex[n];
		ft_putchar(n);
	}
	return (len);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long long	adrr;

	adrr = (unsigned long long)ptr;
	ft_putstr("0x");
	if (!adrr)
		ft_putstr("0");
	else
		ft_print_hexa(adrr);
	return (len_number(adrr));
}
/*
#include <stdio.h>

int	main(void)
{
	int *ptr;
	int a = 3;

	ptr = &a;

	ft_print_ptr(ptr);

	printf("\n%p", ptr);
	return (0);
}*/