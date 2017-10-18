/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 22:02:05 by aoudin            #+#    #+#             */
/*   Updated: 2017/01/14 22:12:09 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# include "libft.h"

# define BUFF_SIZE 64

# define TMP elem->tmp
# define TMP2 elem->tmp2
# define FD elem->fd

typedef struct		s_line
{
	char			*tmp;
	char			*tmp2;
	int				fd;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
