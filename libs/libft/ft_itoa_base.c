/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 14:19:04 by aoudin            #+#    #+#             */
/*   Updated: 2016/07/06 15:40:35 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoa_bis(long int tmp, int a, char *str, int base)
{
	const char	*baze = "0123456789abcdef";

	while (tmp)
	{
		str[--a] = baze[tmp % base];
		tmp /= base;
	}
	return (str);
}

char			*ft_itoa_base(int nb, int base)
{
	char		*str;
	long int	tmp;
	int			a;

	tmp = nb;
	a = 0;
	while (nb)
	{
		a++;
		nb /= base;
	}
	if (tmp == 0 || (tmp < 0 && base == 10))
		a++;
	if (!(str = (char*)malloc(sizeof(char) * (a + 1))))
		return (NULL);
	str[a] = '\0';
	if (tmp < 0)
	{
		if (base == 10)
			str[0] = '-';
		tmp = tmp * -1;
	}
	if (tmp == 0)
		str[0] = '0';
	return (ft_itoa_bis(tmp, a, str, base));
}
