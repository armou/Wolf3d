/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:57:45 by aoudin            #+#    #+#             */
/*   Updated: 2017/04/01 20:48:32 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		ft_initkey(void *arg, int keycode)
{
	(void)arg;
	(void)keycode;
}

void		ft_initmouse(int button, int x, int y, void *arg)
{
	(void)arg;
	(void)button;
	(void)x;
	(void)y;
}

int			ft_keypress(int keycode, t_env *v)
{
	v->pfonct_key[keycode](v, keycode);
	return (0);
}

static void	ft_addr_pfonct_key(t_env *v)
{
	v->pfonct_key[53] = &ft_ptr_exit;
	v->pfonct_key[123] = &ft_movlr;
	v->pfonct_key[124] = &ft_movlr;
	v->pfonct_key[126] = &ft_movfb;
	v->pfonct_key[125] = &ft_movfb;
	v->pfonct_key[12] = &ft_rotleft;
	v->pfonct_key[14] = &ft_rotright;
	v->pfonct_key[49] = &ft_activate;
}

void		ft_ptr_ft(t_env *v)
{
	int		i;

	i = -1;
	while (++i < 280)
		v->pfonct_key[i] = ft_initkey;
	i = -1;
	while (++i < 10)
		v->pfonct_mouse[i] = ft_initmouse;
	ft_addr_pfonct_key(v);
}
