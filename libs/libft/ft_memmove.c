/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 18:53:33 by aoudin            #+#    #+#             */
/*   Updated: 2016/04/17 19:02:58 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src2;
	char	*dst2;

	src2 = (char*)src;
	dst2 = (char*)dst;
	if (src2 < dst2)
	{
		src2 = src2 + len - 1;
		dst2 = dst2 + len - 1;
		while (len > 0)
		{
			*dst2-- = *src2--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*dst2++ = *src2++;
			len--;
		}
	}
	return (dst);
}
