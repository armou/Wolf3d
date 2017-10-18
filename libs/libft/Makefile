# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoudin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/18 11:41:39 by aoudin            #+#    #+#              #
#    Updated: 2017/01/20 16:55:18 by aoudin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRC = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_strtrim.c \
		ft_strsub.c \
		ft_strnjoinfree.c \
		ft_strsplit.c \
		ft_strnew.c \
		ft_strnequ.c \
		ft_strmapi.c \
		ft_strmap.c \
		ft_strlen.c \
		ft_strjoin.c \
		ft_strnjoin.c \
		ft_striteri.c \
		ft_striter.c \
		ft_strequ.c \
		ft_strdup.c \
		ft_strdel.c \
		ft_strcpy.c \
		ft_strclr.c \
		ft_memdel.c \
		ft_memalloc.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_atoi.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_ishexa.c \
		ft_memmove.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_memcpy.c \
		ft_strstr.c \
		ft_strcat.c \
		ft_strncpy.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_itoa.c \
		ft_putnbr_fd.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_memccpy.c \
		ft_putendl_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_itoa_base.c \
		ft_print_memory.c \
		ft_swap_bits.c \
		ft_reverse_bits.c \
		ft_print_bits.c \
		ft_strjoinfree.c \
		ft_strndup.c \
		ft_convert_base.c \
		get_next_line.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
