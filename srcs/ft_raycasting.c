/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 20:52:25 by aoudin            #+#    #+#             */
/*   Updated: 2017/04/01 20:48:10 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_dda(t_env *v)
{
	HIT = 0;
	while (HIT == 0)
	{
		if (D_SIDEX < D_SIDEY)
		{
			D_SIDEX += D_DELTAX;
			MAPX += STEPX;
			SIDE = 0;
		}
		else
		{
			D_SIDEY += D_DELTAY;
			MAPY += STEPY;
			SIDE = 1;
		}
		if (TAB[MAPX][MAPY] >= 'A')
		{
			HIT = 1;
		}
	}
}

void	ft_calc_step(t_env *v)
{
	if (RAYDIRX < 0)
	{
		STEPX = -1;
		D_SIDEX = (RAYPOSX - MAPX) * D_DELTAX;
	}
	else
	{
		STEPX = 1;
		D_SIDEX = (MAPX + 1.0 - RAYPOSX) * D_DELTAX;
	}
	if (RAYDIRY < 0)
	{
		STEPY = -1;
		D_SIDEY = (RAYPOSY - MAPY) * D_DELTAY;
	}
	else
	{
		STEPY = 1;
		D_SIDEY = (MAPY + 1.0 - RAYPOSY) * D_DELTAY;
	}
}

void	ft_calc_dist(t_env *v)
{
	if (SIDE == 0)
		D_PERPWALL = (MAPX - RAYPOSX + (1 - STEPX) / 2) / RAYDIRX;
	else
		D_PERPWALL = (MAPY - RAYPOSY + (1 - STEPY) / 2) / RAYDIRY;
	LINEHEIGHT = (int)(HEIGHT / D_PERPWALL);
	DRAWSTART = -LINEHEIGHT / 2 + HEIGHT / 2;
	(DRAWSTART < 0) ? DRAWSTART = 0 : 0;
	DRAWEND = LINEHEIGHT / 2 + HEIGHT / 2;
	DRAWEND = (DRAWEND >= HEIGHT) ? HEIGHT - 1 : DRAWEND;
}

void	ft_raycast_wall(t_env *v, int x)
{
	CAMX = 2 * x / (double)WIDTH - 1;
	RAYPOSX = POSX;
	RAYPOSY = POSY;
	RAYDIRX = DIRX + PLANEX * CAMX;
	RAYDIRY = DIRY + PLANEY * CAMX;
	MAPX = (int)RAYPOSX;
	MAPY = (int)RAYPOSY;
	D_DELTAX = sqrt(1 + (RAYDIRY * RAYDIRY) / (RAYDIRX * RAYDIRX));
	D_DELTAY = sqrt(1 + (RAYDIRX * RAYDIRX) / (RAYDIRY * RAYDIRY));
	ft_calc_step(v);
	ft_dda(v);
	ft_calc_dist(v);
	ft_print_wall(v, x);
}
