/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 15:31:09 by aoudin            #+#    #+#             */
/*   Updated: 2016/07/06 15:38:34 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	int				i;
	unsigned char	mask;
	unsigned char	masked_octet;
	unsigned char	bit;

	i = 7;
	while (i >= 0)
	{
		mask = 1 << i;
		masked_octet = octet & mask;
		bit = masked_octet >> i;
		ft_putchar('0' + bit);
		i--;
	}
}
