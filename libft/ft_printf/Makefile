# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 09:38:53 by nsouchal          #+#    #+#              #
#    Updated: 2024/05/24 08:52:10 by tnicolau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

DIR_BUILD	=	.build/
DIR_SRCS 	=	srcs/

SRC_FILE	=	ft_printf.c \
				printf_c.c \
				printf_d_i.c \
				printf_s.c \
				printf_u.c \
				printf_xlow_xupp.c \
				printf_p.c

HEADERFILES = ft_printf.h

SRCS	=	$(addprefix $(DIR_SRCS),$(SRC_FILE))
OBJS	=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS))

CC = cc
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(DIR_BUILD)%.o: %.c $(HEADERFILES) Makefile
				mkdir -p $(shell dirname $@)
				$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(DIR_BUILD)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
