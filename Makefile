# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 14:18:46 by hclaude           #+#    #+#              #
#    Updated: 2024/03/15 16:51:40 by hclaude          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

RM = @rm -rf

CC := @cc
AR := @ar
CFLAGS := -Wall -Werror -Wextra

LIBFT = lib/turbo_libft/libft.a

OBJFILES = $(SRCFILES:.c=.o)

SRCFILES = src/count_point_and_lines.c src/free.c src/get_color.c \
src/get_finals_maps.c src/init_parsing.c src/rotation.c main.c \
src/draw_the_map.c src/utils.c

all : $(NAME)

$(NAME) : $(OBJFILES) | mlx libft
	@$(CC) $(CFLAGS) $(OBJFILES) -lft -lglfw -Llib/MLX42/build/ -Llib/turbo_libft/ -lmlx42 -o $@ -lm

mlx :
	@cmake lib/MLX42 -B lib/MLX42/build && cmake --quiet --build lib/MLX42/build -j4

libft :
	@make -s -C lib/turbo_libft/

clean :
	$(RM) lib/MLX42/build
	@make -s clean -C lib/turbo_libft/
	$(RM) $(OBJFILES)
	@echo clean done ! ✅

fclean : clean
	@make -s fclean -C lib/turbo_libft/
	$(RM) $(NAME)

re : fclean all