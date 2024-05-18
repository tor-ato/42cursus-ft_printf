/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:51:02 by tkitahar          #+#    #+#             */
/*   Updated: 2024/05/17 17:27:46 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	ft_putnbr(long nbr, char *base)
{
	int	len;
	int	base_len;

	len = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr < base_len)
		len += ft_putchar(base[nbr]);
	else
	{
		len += ft_putnbr(nbr / base_len, base);
		len += ft_putnbr(nbr % base_len, base);
	}
	return (len);
}
