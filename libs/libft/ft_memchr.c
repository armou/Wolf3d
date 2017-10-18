/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:25:18 by aoudin            #+#    #+#             */
/*   Updated: 2016/05/25 17:20:00 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*a;
	unsigned int	i;

	i = 0;
	a = (char *)s;
	while (i < n)
	{
		if (a[i] == (char)c)
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}
