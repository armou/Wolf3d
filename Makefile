# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoudin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/14 16:43:40 by aoudin            #+#    #+#              #
#    Updated: 2017/04/01 19:45:17 by aoudin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Wolf3d

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

LIBS = -LLibs/libft/ -LLibs/minilibx_macos/

SRCS = 	srcs/main.c \
		srcs/ft_init_event.c \
		srcs/ft_load_tex.c \
		srcs/ft_raycasting.c \
		srcs/ft_skycasting.c \
		srcs/ft_floorcasting.c \
		srcs/ft_draw.c \
		srcs/ft_valid.c \
		srcs/ptr_ft.c \
		srcs/ptr_ft2.c

OBJ = $(SRCS:.c=.o)

$(NAME) : $(OBJ)
	@make -s -C libs/libft
	@echo "Libft Compiled"
	@make -s -C libs/minilibx_macos
	@echo "Minilibx Compiled"
	@$(CC) $(LIBS) -lft -lmlx -framework OpenGL -framework AppKit -o $@ $^
	@echo "Wolf3d Compiled"

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean :
	@make clean -s -C libs/libft
	@echo ".o Libft delete"
	@make clean -s -C libs/minilibx_macos
	@echo ".o Minilibx delete"
	@$(RM) $(OBJ)
	@echo ".o Wolf3d delete"

fclean : clean
	@$(RM) libs/libft/libft.a
	@echo "libft.a delete"
	@$(RM) libs/minilibx_macos/libmlx.a
	@echo "libmlx.a delete"
	@$(RM) $(NAME)
	@echo "Wolf3d delete"

re : fclean all
