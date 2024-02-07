# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 14:18:46 by hclaude           #+#    #+#              #
#    Updated: 2024/02/07 15:37:20 by hclaude          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a

RM = rm -rf

CC := cc
AR := ar
ARFLAGS := rcs
CFLAGS := -Wall -Werror -Wextra

LIBFT = lib/turbo_libft/libft.a

OBJFILES = $(SRCFILES:.c=.o)

SRCFILES = src/count_point_and_lines.c src/free.c src/get_color.c \
src/get_finals_maps.c src/init_parsing.c

all : $(NAME)

$(NAME) : $(OBJFILES)
	make big -C lib/turbo_libft/
	mv $(LIBFT) .
	mv libft.a $(NAME)
	$(AR) $(ARFLAGS) $@ $^

clean :
	make clean -C lib/turbo_libft/
	$(RM) $(OBJFILES)

fclean : clean
	$(RM) $(NAME)

re : fclean all