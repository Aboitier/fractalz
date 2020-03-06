# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboitier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 18:46:30 by aboitier          #+#    #+#              #
#    Updated: 2020/03/03 22:09:45 by aboitier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=address

FILES	=	main.c				\
			init.c				\
			hooks.c				\
			image.c				\
			utils.c				\
			threads.c			\
			draw_fracts.c		\
			zoom.c				\
			max_iter.c			\
			#draw_mandelbrot.c	\

SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(addprefix build/, $(FILES:.c=.o))

FRAMEWORKS = -framework OpenGL -framework AppKit

INC_MINILIBX = -I minilibx
LINK_MINILIBX = -lmlx
MINILIBX = $(INC_MINILIBX) $(LINK_MINILIBX)

LIBFT = -I libft
LINK_FT = -L libft/ -lft
FT = $(LIBFT) $(LINK_FT)

#LIBCG = -I libcg
#LINK_CG = -L libcg -lcg
#CG = $(LIBCG) $(LINK_CG)

all: $(NAME)

libft/libft.a:
	make -C libft re

re: fclean all

regfx:
	make -C libcg re
	make re
	
libcg/libcg.a:
	make -C libcg re


$(NAME): libft/libft.a $(OBJS) #libcg/libcg.a 
	@$(CC) $(CFLAGS) $(MINILIBX) $(FT) $(CG) \
		-I includes/ $(FRAMEWORKS) $(OBJS) -o $(NAME)
	@echo "$@ has been created, run with ./$@ fractal-name"

build:
	mkdir build

build/%.o: srcs/%.c | build
	@echo "Building $@"
	@$(CC) $(CFLAGS) $(INC_MINILIBX) $(LIBFT) -I . -c $< -o $@

clean:
	rm -rf build

tclean:
	make -C libft fclean
	make -C libcg fclean
	make -C minilibx clean
	make fclean

fclean: clean
	rm -f $(NAME)

