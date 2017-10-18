/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 12:02:07 by aoudin            #+#    #+#             */
/*   Updated: 2017/01/12 15:50:16 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnjoin(char const *s1, char const *s2, size_t length)
{
	char	*str;

	str = NULL;
	if (!s1 || !s2)
		return (NULL);
	if (s1 && s2)
	{
		str = ft_strnew(ft_strlen(s1) + length);
		if (str)
		{
			ft_strcpy(str, s1);
			ft_strncat(str, s2, length);
		}
		free((char*)s1);
	}
	return (str);
}
