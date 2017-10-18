/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:11:48 by aoudin            #+#    #+#             */
/*   Updated: 2017/10/18 18:59:35 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void			ft_launch_raycast(t_env *v)
{
	int		x;

	x = -1;
	while (++x < WIDTH)
	{
		ft_raycast_wall(v, x);
	}
}

void			ft_init_var(t_env *v)
{
	POSX = 2.0f;
	POSY = 2.0f;
	PLANEX = 0.0f;
	PLANEY = 0.66;
	DIRX = -1;
	DIRY = 0;
	MS = 0.4;
	ROTSPEED = 0.1;
	COLOR = 0;
	F_XDRAW = 0.0f;
	F_YDRAW = 0.0f;
}

int				ft_wolf(t_env *v)
{
	ft_launch_raycast(v);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (0);
}

t_env			*ft_create_struct(int fd)
{
	t_env	*v;

	if (!(v = (t_env*)ft_memalloc(sizeof(t_env))))
		exit(0);
	if (!(v->img = (t_img*)ft_memalloc(sizeof(t_img))))
		exit(0);
	if (!(v->wtex = (t_tex*)ft_memalloc(sizeof(t_tex))))
		exit(0);
	if (!(v->ftex = (t_tex_f*)ft_memalloc(sizeof(t_tex_f))))
		exit(0);
	if (!(v->wolf = (t_w*)ft_memalloc(sizeof(t_w))))
		exit(0);
	if (!(v->sp = (t_sprite*)ft_memalloc(sizeof(t_sprite))))
		exit(0);
	ft_ptr_ft(v);
	ft_parse_wolf(v, fd);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 800, 500, WIDTH, HEIGHT, "Wolf3d");
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT, 0xFFFFFF);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	ft_init_tex(v);
	return (v);
}

int				main(int ac, char **av)
{
	t_env	*v;
	int		fd;

	if (ac != 2)
		ft_putendl("Usage : ./Wolf3d <map>");
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd > 0)
		{
			v = ft_create_struct(fd);
			mlx_loop_hook(MLX, ft_wolf, v);
			mlx_hook(WIN, KeyPress, KeyPressMask, ft_keypress, v);
			mlx_hook(WIN, DestroyNotify, Button1MotionMask, ft_exitprog, v);
			mlx_loop(MLX);
		}
		else
			ft_putendl("Invalid Map");
		close(fd);
	}
	return (0);
}
