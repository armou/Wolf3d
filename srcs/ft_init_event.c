/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 19:00:26 by aoudin            #+#    #+#             */
/*   Updated: 2017/04/01 20:48:51 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		ft_ptr_exit(void *arg, int keycode)
{
	(void)arg;
	(void)keycode;
	ft_exit(2);
}

int			ft_exitprog(t_env *v)
{
	(void)v;
	ft_exit(2);
	return (0);
}

void		ft_exit(int i)
{
	if (i == 1)
		ft_putendl("Map error");
	if (i == 2)
		ft_putendl("Thanks for playing !");
	exit(0);
}

int			ft_calc_x(char *line)
{
	int		i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void		ft_parse_wolf(t_env *v, int fd)
{
	char	*line;

	YMAX = 0;
	line = NULL;
	MAP = ft_strnew(BUFF_SIZE);
	while (get_next_line(fd, &line))
	{
		if (line[0] == 0)
			ft_exit(1);
		!XMAX ? XMAX = ft_calc_x(line) : 0;
		MAP = ft_strjoinfree(MAP, line);
		MAP = ft_strjoinfree(MAP, "\n");
		YMAX++;
		free(line);
	}
	!XMAX ? ft_exit(1) : 0;
	TAB = ft_strsplit(MAP, '\n');
	ft_isvalid(MAP, TAB, XMAX, YMAX);
	ft_init_var(v);
}
