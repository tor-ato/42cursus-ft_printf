/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:42:12 by tkitahar          #+#    #+#             */
/*   Updated: 2024/05/18 14:13:38 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_printf(const char *, ...);

int	ft_putchar(char c);
int	ft_putstr(char *c);
int	ft_putnbr(long adres, char *base);
int	ft_putadres(uintptr_t nbr, char *base);