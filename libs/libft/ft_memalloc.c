/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 17:27:27 by aoudin            #+#    #+#             */
/*   Updated: 2016/04/17 17:32:12 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	tmp = NULL;
	if (size)
	{
		tmp = malloc(size);
		if (tmp)
			ft_bzero(tmp, size);
	}
	return (tmp);
}
