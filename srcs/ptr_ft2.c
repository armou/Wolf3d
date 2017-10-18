/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_ft2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:58:54 by aoudin            #+#    #+#             */
/*   Updated: 2017/04/01 20:48:28 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void			ft_movfb(void *arg, int keycode)
{
	t_env		*v;

	v = arg;
	if (keycode == 126)
	{
		if ((TAB[(int)(POSX + DIRX * MS)][(int)POSY] <= '9') &&
			(TAB[(int)((POSX + DIRX * MS) + OFFSET)][(int)POSY] <= '9') &&
			(TAB[(int)((POSX + DIRX * MS) - OFFSET)][(int)POSY] <= '9'))
			POSX = POSX + DIRX * MS;
		if ((TAB[(int)POSX][(int)(POSY + DIRY * MS)] <= '9') &&
			(TAB[(int)POSX][(int)((POSY + DIRY * MS) + OFFSET)] <= '9') &&
			(TAB[(int)POSX][(int)((POSY + DIRY * MS) - OFFSET)] <= '9'))
			POSY = POSY + DIRY * MS;
	}
	else if (keycode == 125)
	{
		if ((TAB[(int)(POSX - DIRX * MS)][(int)POSY] <= '9') &&
			(TAB[(int)((POSX - DIRX * MS) + OFFSET)][(int)POSY] <= '9') &&
			(TAB[(int)((POSX - DIRX * MS) - OFFSET)][(int)POSY] <= '9'))
			POSX = POSX - DIRX * MS;
		if ((TAB[(int)POSX][(int)(POSY - DIRY * MS)] <= '9') &&
			(TAB[(int)POSX][(int)((POSY - DIRY * MS) + OFFSET)] <= '9') &&
			(TAB[(int)POSX][(int)((POSY - DIRY * MS) - OFFSET)] <= '9'))
			POSY = POSY - DIRY * MS;
	}
}

void			ft_movlr(void *arg, int keycode)
{
	t_env		*v;

	v = arg;
	if (keycode == 124)
	{
		if ((TAB[(int)(POSX + PLANEX * MS)][(int)POSY] <= '9') &&
			(TAB[(int)((POSX + PLANEX * MS) + OFFSET)][(int)POSY] <= '9') &&
			(TAB[(int)((POSX + PLANEX * MS) - OFFSET)][(int)POSY] <= '9'))
			POSX = POSX + PLANEX * MS;
		if ((TAB[(int)POSX][(int)(POSY + PLANEY * MS)] <= '9') &&
			(TAB[(int)POSX][(int)((POSY + PLANEY * MS) + OFFSET)] <= '9') &&
			(TAB[(int)POSX][(int)((POSY + PLANEY * MS) - OFFSET)] <= '9'))
			POSY = POSY + PLANEY * MS;
	}
	else if (keycode == 123)
	{
		if ((TAB[(int)(POSX - PLANEX * MS)][(int)POSY] <= '9') &&
			(TAB[(int)((POSX - PLANEX * MS) + OFFSET)][(int)POSY] <= '9') &&
			(TAB[(int)((POSX - PLANEX * MS) - OFFSET)][(int)POSY] <= '9'))
			POSX = POSX - PLANEX * MS;
		if ((TAB[(int)POSX][(int)(POSY - PLANEY * MS)] <= '9') &&
			(TAB[(int)POSX][(int)((POSY - PLANEY * MS) + OFFSET)] <= '9') &&
			(TAB[(int)POSX][(int)((POSY - PLANEY * MS) - OFFSET)] <= '9'))
			POSY = POSY - PLANEY * MS;
	}
}

void			ft_rotright(void *arg, int keycode)
{
	t_env		*v;
	double		dirxtmp;
	double		planextmp;

	(void)keycode;
	v = arg;
	dirxtmp = DIRX;
	DIRX = DIRX * cos(-ROTSPEED) - DIRY * sin(-ROTSPEED);
	DIRY = dirxtmp * sin(-ROTSPEED) + DIRY * cos(-ROTSPEED);
	planextmp = PLANEX;
	PLANEX = PLANEX * cos(-ROTSPEED) - PLANEY * sin(-ROTSPEED);
	PLANEY = planextmp * sin(-ROTSPEED) + PLANEY * cos(-ROTSPEED);
	ROTSPEED = 0.1;
}

void			ft_rotleft(void *arg, int keycode)
{
	t_env		*v;
	double		dirxtmp;
	double		planextmp;

	(void)keycode;
	v = arg;
	dirxtmp = DIRX;
	DIRX = DIRX * cos(ROTSPEED) - DIRY * sin(ROTSPEED);
	DIRY = dirxtmp * sin(ROTSPEED) + DIRY * cos(ROTSPEED);
	planextmp = PLANEX;
	PLANEX = PLANEX * cos(ROTSPEED) - PLANEY * sin(ROTSPEED);
	PLANEY = planextmp * sin(ROTSPEED) + PLANEY * cos(ROTSPEED);
	ROTSPEED = 0.1;
}

void			ft_activate(void *arg, int keycode)
{
	t_env		*v;

	v = arg;
	(void)keycode;
	if (TAB[(int)(POSX + DIRX)][(int)(POSY + DIRY)] == 'D')
		TAB[(int)(POSX + DIRX)][(int)(POSY + DIRY)] = '8';
	else if (TAB[(int)(POSX + DIRX)][(int)(POSY + DIRY)] == '8')
		TAB[(int)(POSX + DIRX)][(int)(POSY + DIRY)] = 'D';
}
