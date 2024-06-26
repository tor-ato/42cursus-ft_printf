/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:42:12 by tkitahar          #+#    #+#             */
/*   Updated: 2024/05/19 15:45:53 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

int	ft_printf(const char *fmt, ...);

int	ft_putchar(char c);
int	ft_putstr(char *c);
int	ft_putnbr(long nbr, char *base);
int	ft_putaddress(uintptr_t nbr, char *base);

#endif
