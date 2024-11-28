/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:07:48 by isall             #+#    #+#             */
/*   Updated: 2024/10/15 13:31:27 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_number(int nbr)
{
	int		len;
	long	n;

	n = nbr;
	len = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0 || n < 0)
		len = 1;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = len_number(n);
	if (n == -2147483648)
	{
		(write(1, "-2147483648", 11));
		return (len);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n >= 0 && n <= 9)
	{
		n = n + '0';
		ft_putchar(n);
	}
	return (len);
}
