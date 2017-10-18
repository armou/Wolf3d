/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:40:19 by aoudin            #+#    #+#             */
/*   Updated: 2017/10/18 19:14:20 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

double		ft_dir_to_deg(double dir_x, double dir_y)
{
	double result;

	if (dir_x != 0)
		result = atan(dir_y / dir_x) * 180.0 / 3.14159265359;
	else
	{
		if (dir_y > 0)
			result = 90;
		else
			result = -90;
	}
	if (result < 0)
		result = 180 + result;
	if (dir_y <= 0)
		result = 180 + result;
	return (result);
}

void		ft_skybox(t_env *v, int x, int y)
{
	double		sky_x;
	double		sky_y;
	int			i;

	i = 0;
	sky_x = ft_dir_to_deg(RAYDIRX, RAYDIRY);
	sky_x = (((double)sky_x / 360.0) * 9781);
	sky_x = 9781 - sky_x;
	if (y < HEIGHT)
	{
		sky_y = ((double)y / ((double)HEIGHT)) * 1574;
		COLOR = mlx_get_pixel_clr(SKYBOX, sky_x, sky_y);
		*(int*)&DATA[(y * SIZELINE + x * (BPP / 8))] = COLOR;
	}
	(void)x;
}
