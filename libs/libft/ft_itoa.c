/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:34:47 by aoudin            #+#    #+#             */
/*   Updated: 2016/05/25 17:51:46 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoanext(int nb, char *str, int i)
{
	while (nb)
	{
		str[--i] = '0' + (nb % 10);
		nb = nb / 10;
	}
	return (str);
}

static char		*ft_neg(int *nb, char *str)
{
	if (*nb < 0)
	{
		str[0] = '-';
		*nb = -*nb;
	}
	return (str);
}

static int		ft_min(int nb)
{
	if (nb == -2147483648)
		return (1);
	return (0);
}

char			*ft_itoa(int nb)
{
	int		i;
	int		tmp;
	char	*str;

	i = 0;
	tmp = nb;
	if (ft_min(nb))
		return (ft_strdup("-2147483648"));
	while (tmp != 0)
	{
		tmp = tmp / 10;
		i++;
	}
	if (nb == 0)
		i++;
	if (nb < 0)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i] = '\0';
	str = ft_neg(&nb, str);
	if (nb == 0)
		str[0] = '0';
	return (ft_itoanext(nb, str, i));
}
