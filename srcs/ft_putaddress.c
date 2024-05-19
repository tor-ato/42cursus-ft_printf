/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:50:51 by tkitahar          #+#    #+#             */
/*   Updated: 2024/05/19 15:56:30 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(uintptr_t nbr, char *base)
{
	int			len;
	uintptr_t	base_len;

	len = 0;
	base_len = 0;
	len += ft_putstr("0x");
	base_len = ft_strlen(base);
	if (nbr < base_len)
		len += ft_putchar(base[nbr]);
	else
	{
		len += ft_putnbr(nbr / base_len, base);
		len += ft_putnbr(nbr % base_len, base);
	}
	return (len);
}
