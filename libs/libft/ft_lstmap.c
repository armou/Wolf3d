/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:30:46 by aoudin            #+#    #+#             */
/*   Updated: 2016/05/25 16:31:46 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*cpy;
	t_list	*rabbit;
	t_list	*turtle;

	cpy = NULL;
	if (lst)
	{
		cpy = f(lst);
		if (!(cpy = ft_lstnew(cpy->content, cpy->content_size)))
			return (NULL);
		lst = lst->next;
	}
	rabbit = cpy;
	while (lst)
	{
		turtle = rabbit;
		rabbit = f(lst);
		if (!(rabbit = ft_lstnew(rabbit->content, rabbit->content_size)))
			return (NULL);
		turtle->next = rabbit;
		lst = lst->next;
	}
	return (cpy);
}
