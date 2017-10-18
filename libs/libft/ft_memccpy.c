/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:01:02 by aoudin            #+#    #+#             */
/*   Updated: 2016/05/25 13:59:49 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n-- > 0)
	{
		*((unsigned char *)dst) = *((unsigned char *)src);
		if (*((unsigned char *)src) == (unsigned char)c)
			return (dst + 1);
		src++;
		dst++;
	}
	return (NULL);
}
