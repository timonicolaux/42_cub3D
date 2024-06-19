# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 12:39:14 by nsouchal          #+#    #+#              #
#    Updated: 2024/05/24 08:52:03 by tnicolau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

DIR_BUILD	=	.build/
DIR_SRCS 	=	srcs/
DIR_SRCS_BONUS 	=	srcs_bonus/

SRC_FILE	=	ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_split.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

BONUS	=	ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

HEADERFILES	=	libft.h

OBJS	=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS))
SRCS	=	$(addprefix $(DIR_SRCS),$(SRC_FILE))

BONUS_OBJS	=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS_BONUS))
SRCS_BONUS	=	$(addprefix $(DIR_SRCS_BONUS),$(BONUS))

DIR_FTPRINTF	=	ft_printf/

FLAGS	=	-Wall -Werror -Wextra

CC	=	cc


all:	ft_printf $(NAME)

$(NAME):	$(OBJS) $(DIR_FTPRINTF)libftprintf.a
			cd $(DIR_FTPRINTF) && cp libftprintf.a ../$(NAME)
			ar rcs $(NAME) $(OBJS)
			ranlib $(NAME)

$(DIR_BUILD)%.o: %.c $(HEADERFILES) Makefile
				mkdir -p $(shell dirname $@)
				$(CC) $(FLAGS) -c $< -o $@

ft_printf:
				$(MAKE) -C $(DIR_FTPRINTF)

clean:
	rm -rf $(DIR_BUILD)
	$(MAKE) -C $(DIR_FTPRINTF) clean

fclean:	clean
	rm -f $(NAME)
	$(MAKE) -C $(DIR_FTPRINTF) fclean

bonus	:
	$(MAKE) $(NAME) SRC="$(SRCS) $(SRCS_BONUS)"

re:	fclean all

.PHONY:	all clean fclean bonus re ft_printf
