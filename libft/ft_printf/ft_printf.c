/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:04:22 by isall             #+#    #+#             */
/*   Updated: 2024/11/15 14:02:09 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

static int	convers(char unit, va_list args)
{
	if (unit == '%')
		return (write(1, "%", 1));
	else if (unit == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (unit == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (unit == 'd' || unit == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (unit == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (unit == 'p')
		return (ft_print_ptr(va_arg(args, void *)) + 2);
	else if (unit == 'x')
		return (ft_print_hex(va_arg(args, unsigned int)));
	else if (unit == 'X')
		return (ft_print_hexx(va_arg(args, unsigned int)));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		j;

	count = 0;
	j = 0;
	va_start(args, format);
	while (format[j])
	{
		if (format[j] == '%')
		{
			while (format[j + 1] == ' ')
				j++;
			count += convers(format[j + 1], args);
			j += 2;
		}
		else
		{
			write(1, &format[j], 1);
			count++;
			j++;
		}
	}
	va_end(args);
	return (count);
}
