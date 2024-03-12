# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 14:18:46 by hclaude           #+#    #+#              #
#    Updated: 2024/03/12 14:55:37 by hclaude          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

RM = @rm -rf

CC := @cc
AR := @ar
CFLAGS := -Wall -Werror -Wextra -g3

LIBFT = lib/turbo_libft/libft.a

OBJFILES = $(SRCFILES:.c=.o)

SRCFILES = src/count_point_and_lines.c src/free.c src/get_color.c \
src/get_finals_maps.c src/init_parsing.c src/rotation.c main.c \
src/draw_the_map.c src/utils.c

all : $(NAME)

$(NAME) : $(OBJFILES) mlx
	@make big -C lib/turbo_libft/
	@mv $(LIBFT) .
	@$(CC) $(CFLAGS) $(OBJFILES) libft.a libmlx42.a -lglfw -lm -o $(NAME)

mlx :
	@cd lib/MLX42 && cmake -B build
	@cd ../../
	@make -C lib/MLX42/build/
	@mv lib/MLX42/build/libmlx42.a .

clean :
	@make clean -C lib/MLX42/build/
	@make clean -C lib/turbo_libft/
	@$(RM) $(OBJFILES)

fclean : clean
	$(RM) libft.a libmlx42.a $(NAME)

re : fclean all