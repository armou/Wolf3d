/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floorcasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:43:56 by aoudin            #+#    #+#             */
/*   Updated: 2017/04/01 20:50:11 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_color_floor_tex(t_env *v, int x, int y)
{
	if (TAB[(int)F_XDRAW][(int)F_YDRAW] == '0')
	{
		COLOR = mlx_get_pixel_clr(GRASS, x, y);
		EXT = 1;
	}
	else
	{
		COLOR = mlx_get_pixel_clr(MARBLE, x, y);
		EXT = 0;
	}
}

void	ft_floor_calc_dir(t_env *v)
{
	if (SIDE == 0 && RAYDIRX > 0)
	{
		FLOORX = MAPX;
		FLOORY = MAPY + WALLX;
	}
	else if (SIDE == 0 && RAYDIRX < 0)
	{
		FLOORX = MAPX + 1.0;
		FLOORY = MAPY + WALLX;
	}
	else if (SIDE == 1 && RAYDIRY > 0)
	{
		FLOORX = MAPX + WALLX;
		FLOORY = MAPY;
	}
	else
	{
		FLOORX = MAPX + WALLX;
		FLOORY = MAPY + 1.0;
	}
}

void	ft_ceilcasting(t_env *v, int x, int y)
{
	(void)x;
	(void)y;
	if (TAB[(int)F_XDRAW][(int)F_YDRAW] == '1')
	{
		COLOR = mlx_get_pixel_clr(CEIL, FLOORTEX_X, FLOORTEX_Y);
	}
}

void	ft_floorcasting(t_env *v, int y, int a)
{
	double		i;

	if (SIDE == 0)
		WALLX = RAYPOSY + D_PERPWALL * RAYDIRY;
	else
		WALLX = RAYPOSX + D_PERPWALL * RAYDIRX;
	WALLX -= floor(WALLX);
	ft_floor_calc_dir(v);
	D_WALL = D_PERPWALL;
	D_PLAYER = 0.0f;
	(DRAWEND < 0) ? DRAWEND = HEIGHT : 0;
	if (y < HEIGHT)
	{
		(a == 0) ? y = HEIGHT - y : 0;
		D_DRAW = HEIGHT / (2.0f * y - HEIGHT);
		i = (D_DRAW - D_PLAYER) / (D_WALL - D_PLAYER);
		F_XDRAW = i * FLOORX + (1.0f - i) * POSX;
		F_YDRAW = i * FLOORY + (1.0f - i) * POSY;
		FLOORTEX_X = (int)(F_XDRAW * FTEX) % FTEX;
		FLOORTEX_Y = (int)(F_YDRAW * FTEX) % FTEX;
		if (a == 1)
			ft_color_floor_tex(v, FLOORTEX_X, FLOORTEX_Y);
		else
			ft_ceilcasting(v, FLOORTEX_X, FLOORTEX_Y);
	}
}
