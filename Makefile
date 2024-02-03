# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 14:18:46 by hclaude           #+#    #+#              #
#    Updated: 2024/02/03 02:42:15 by hclaude          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a

RM = rm -rf

CC := cc
AR := ar
ARFLAGS := rcs
CFLAGS := -Wall -Werror -Wextra

LIBFT = libft/libft.a

OBJFILES = $(SRCFILES:.c=.o)

SRCFILES = #src/parsing.c

all : $(NAME)

$(NAME) : $(OBJFILES)
	make -C libft/
	mv $(LIBFT) .
	mv libft.a $(NAME)
	$(AR) $(ARFLAGS) $@ $^

clean :
	make clean -C libft/
	$(RM) $(OBJFILES)

fclean : clean
	$(RM) $(NAME)

re : fclean all