/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:38:34 by tkitahar          #+#    #+#             */
/*   Updated: 2024/05/16 16:01:47 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libc.h>
#include <stdio.h>
#include <stdlib.h>

int	hundle_format(va_list ap, char str)
{
	int	count;

	count = 0;
	if (str == '%')
		count += ft_pchar(va_arg(ap, int));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
			count += ft_pchar(*str, 1);
		else if (*str == '%' && *(str + 1))
			count += hundle_format(ap, *(++str));
		str++;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	int	ft;
	int	origin;

	ft = ft_printf("ft \t 1234 \n", 1, 2, 3);
	printf("print num \t %d \n", ft);
	origin = printf("or \t  12345 \n", 1);
	printf("print num \t 1234 \n", origin);
	return (0);
}
