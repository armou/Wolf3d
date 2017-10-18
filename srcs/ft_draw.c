/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:26:07 by aoudin            #+#    #+#             */
/*   Updated: 2017/10/18 19:18:42 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		ft_color(int a, int r, int g, int b)
{
	return (((a & 0xff) << 24) + ((r & 0xff) << 16) + ((g & 0xff) << 8) +
			(b & 0xff));
}

void	ft_color_tex(t_env *v, int y, int x)
{
	if (TAB[MAPX][MAPY] == 'A')
		COLOR = mlx_get_pixel_clr(WALL, x, y);
	else if (TAB[MAPX][MAPY] == 'W')
		COLOR = mlx_get_pixel_clr(WINDOW, x, y);
	else if (TAB[MAPX][MAPY] == 'D')
		COLOR = mlx_get_pixel_clr(DOOR, x, y);
	else
		COLOR = 0;
	if (SIDE == 1)
	{
		if ((RAYDIRX >= 0 && RAYDIRY < 0) || (RAYDIRX < 0 && RAYDIRY < 0))
			COLOR = (COLOR >> 1) & 8355711;
	}
}

void	ft_print_tex(t_env *v, int y)
{
	int		i;
	int		texw;
	int		texh;

	i = y * 256 - HEIGHT * 128 + LINEHEIGHT * 128;
	if (SIDE == 0)
		WALLX = RAYPOSY + D_PERPWALL * RAYDIRY;
	else
		WALLX = RAYPOSX + D_PERPWALL * RAYDIRX;
	WALLX -= floor(WALLX);
	texw = (int)(WALLX * (double)(TEX));
	if ((SIDE == 0 && RAYDIRX > 0) || (SIDE == 1 && RAYDIRY < 0))
		texw = (TEX - texw - 1);
	texh = ((i * TEX) / LINEHEIGHT) / 256;
	ft_color_tex(v, texh, texw);
}

void	ft_print_wall(t_env *v, int x)
{
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		if (y <= DRAWEND && y >= DRAWSTART)
		{
			ft_print_tex(v, y);
			*(int*)&DATA[(y * SIZELINE + x * (BPP / 8))] = COLOR;
		}
		else if (y > DRAWEND)
		{
			ft_floorcasting(v, y, 1);
			*(int*)&DATA[(y * SIZELINE + x * (BPP / 8))] = COLOR;
		}
		else
		{
			ft_skybox(v, x, y);
			ft_floorcasting(v, y, 0);
			*(int*)&DATA[(y * SIZELINE + x * (BPP / 8))] = COLOR;
		}
	}
}
