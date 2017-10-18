/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 19:43:41 by aoudin            #+#    #+#             */
/*   Updated: 2017/04/01 20:47:53 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_floor_tex(t_env *v)
{
	GRASS = mlx_xpm_file_to_image(MLX, "tex/GrassTex2.xpm", &FTEX, &FTEX);
	MARBLE = mlx_xpm_file_to_image(MLX, "tex/MarbleTileTex.xpm", &FTEX, &FTEX);
	CEIL = mlx_xpm_file_to_image(MLX, "tex/CeilTex.xpm", &FTEX, &FTEX);
	SKYBOX = mlx_xpm_file_to_image(MLX, "tex/SkyTex.xpm", &STEXW, &STEXH);
}

void	ft_init_tex(t_env *v)
{
	ft_floor_tex(v);
	WALL = mlx_xpm_file_to_image(MLX, "tex/StoneWallTex_1.xpm", &TEX, &TEX);
	WINDOW = mlx_xpm_file_to_image(MLX, "tex/WindowTex.xpm", &TEX, &TEX);
	DOOR = mlx_xpm_file_to_image(MLX, "tex/DoorTex.xpm", &TEX, &TEX);
}
