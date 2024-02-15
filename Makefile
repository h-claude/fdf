# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 14:18:46 by hclaude           #+#    #+#              #
#    Updated: 2024/02/15 02:25:41 by moajili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

RM = rm -rf

CC := @gcc
AR := ar
CFLAGS := -Wall -Werror -Wextra -g3

LIBFT = lib/turbo_libft/libft.a

OBJFILES = $(SRCFILES:.c=.o)

SRCFILES = src/count_point_and_lines.c src/free.c src/get_color.c \
src/get_finals_maps.c src/init_parsing.c main_momo.c

all : $(NAME)

$(NAME) : $(OBJFILES)
	make big -C lib/turbo_libft/
	mv $(LIBFT) .
	$(CC) $(CFLAGS) $(OBJFILES) libft.a -o $(NAME) 

clean :
	make clean -C lib/turbo_libft/
	$(RM) $(OBJFILES)

fclean : clean
	$(RM) $(NAME)

re : fclean all