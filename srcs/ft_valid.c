/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 18:54:13 by aoudin            #+#    #+#             */
/*   Updated: 2017/04/01 20:48:39 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		ft_create_startpoint(char **tab)
{
	if (tab[1][1] > '9' || tab[1][1] < '0')
	{
		tab[1][1] = '0';
		tab[1][2] = '0';
		tab[2][1] = '0';
		tab[2][2] = '0';
	}
}

void		ft_check_map(char **tab, int x, int y)
{
	int		len;
	int		i;

	if (y < 4 || x < 4)
		ft_exit(1);
	len = 0;
	i = -1;
	while (tab[0][len])
		len++;
	while (tab[++i])
	{
		if ((int)(ft_strlen(tab[i])) != len)
			ft_exit(1);
	}
}

void		ft_isvalid(char *str, char **tab, int x, int y)
{
	int		i;
	int		j;

	ft_check_map(tab, x, y);
	i = -1;
	while (str[++i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') ||
				(str[i] >= 'A' && str[i] <= 'Z') || (str[i] == '\n')))
			ft_exit(1);
	}
	i = -1;
	j = -1;
	while (tab[0][++j])
	{
		tab[0][j] = 'A';
		tab[y - 1][j] = 'A';
	}
	while (tab[++i])
	{
		tab[i][x - 1] = 'A';
		tab[i][0] = 'A';
	}
	ft_create_startpoint(tab);
}
