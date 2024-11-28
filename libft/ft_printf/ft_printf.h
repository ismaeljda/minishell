/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:07:17 by isall             #+#    #+#             */
/*   Updated: 2024/11/15 14:01:37 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
// # include "../libft.h"

int		ft_printf(const char *format, ...);
int		ft_putstr(char const *str);
int		ft_putchar(const char c);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_print_ptr(void *ptr);
int		ft_print_hex(unsigned int n);
int		ft_print_hexx(unsigned int n);
size_t	ft_strlen(const char *s);
#endif