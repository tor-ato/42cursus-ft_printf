/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:38:34 by tkitahar          #+#    #+#             */
/*   Updated: 2024/05/14 17:44:04 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libc.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_printchar_count(va_list ap, const char **format)
{
	int	count;

	count = 0;
	printf("\nva_arg(ap, int)1 %d\n", va_arg(ap, int));
	printf("\nva_arg(ap, int)2 %d\n", va_arg(ap, int));
	printf("\nva_arg(ap, int)3 %d\n", va_arg(ap, int));
	printf("\nva_arg(ap, int)4 %d\n", va_arg(ap, int));
	// while (va_arg(ap, int))
	// {
	// 	count++;
	// }
	(void)format;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	count += ft_printchar_count(ap, &format);
	va_end(ap);
	return (count);
}

int	main(void)
{
	int	ft;
	int	origin;

	ft = ft_printf("ft\t12345\n", 1, 2, 3);
	printf("\n%d\n", ft);
	origin = printf("orgn\t12345\n");
	printf("\n%d\n", origin);
	// system("leaks -q a.out");
	return (0);
}
