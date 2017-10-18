/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 15:15:08 by aoudin            #+#    #+#             */
/*   Updated: 2016/07/06 15:37:05 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_hex(int octet, int rem)
{
	char const *base = "0123456789abcdef";

	if (rem > 1)
		ft_putnbr_hex(octet >> 4, rem - 1);
	write(1, base + (octet % 16), 1);
}

static void		ft_putchar_sp(unsigned char const *str)
{
	char const c = *str;

	if (c >= ' ' && c <= '~')
		write(1, str, 1);
	else
		write(1, str, 1);
}

static void		ft_print_number(const unsigned char *addr,
		size_t size, size_t i)
{
	int		a;

	a = 0;
	while (a < 16 && a + i < size)
	{
		ft_putnbr_hex(*(addr + i + a), 2);
		if (a % 2)
			write(1, " ", 1);
		a++;
	}
	while (a < 16)
	{
		write(1, "  ", 2);
		if (a % 2)
			write(1, " ", 1);
		a++;
	}
}

static void		ft_print_characters(const unsigned char *addr,
		size_t size, size_t i)
{
	int		a;

	a = 0;
	while (a < 16 && a + i < size)
	{
		ft_putchar_sp(addr + a + i);
		a++;
	}
}

void			ft_print_memory(const void *addr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_print_number((const unsigned char *)addr, size, i);
		ft_print_characters((const unsigned char *)addr, size, i);
		write(1, "\n", 1);
		i = i + 16;
	}
}
