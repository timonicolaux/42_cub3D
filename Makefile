# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 09:14:12 by nsouchal          #+#    #+#              #
#    Updated: 2024/06/10 15:20:19 by tnicolau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME_BONUS = cub3D_bonus

DIR_BUILD			=	.build/
DIR_BUILD_BONUS		=	.build_bonus/
DIR_SRCS			=	srcs/
DIR_SRCS_BONUS		=	srcs_bonus/
DIR_HEADERS			=	includes/
DIR_HEADERS_BONUS	=	includes_bonus/
DIR_LIBFT			=	libft/
DIR_MLX				=	minilibx-linux/
DIR_PARSING			=	parsing/
DIR_PARSING_BONUS	=	parsing_bonus/

SRC_FILE =	main.c \
			initialisation.c \
			map_checker.c \
			get_next_line.c \
			get_next_line_utils.c \
			$(DIR_PARSING)parsing.c \
			$(DIR_PARSING)parse_textures.c \
			$(DIR_PARSING)parse_map.c \
			$(DIR_PARSING)parsing_utils.c \
			raycasting.c \
			raycasting_utils.c \
			moves.c \
			moves_utils.c \
			utils.c \
			end.c

SRC_FILE_BONUS =	main_bonus.c \
					initialisation_bonus.c \
					initialisation_mlx_bonus.c \
					map_checker_bonus.c \
					get_next_line_bonus.c \
					get_next_line_utils_bonus.c \
					$(DIR_PARSING_BONUS)parsing_bonus.c \
					$(DIR_PARSING_BONUS)parse_textures_bonus.c \
					$(DIR_PARSING_BONUS)parse_map_bonus.c \
					$(DIR_PARSING_BONUS)parsing_utils_bonus.c \
					raycasting_bonus.c \
					raycasting_utils_bonus.c \
					raycasting_utils2_bonus.c \
					moves_bonus.c \
					moves_utils_bonus.c \
					utils_bonus.c \
					end_bonus.c \
					minimap_bonus.c \
					minimap_utils_bonus.c \
					mouse_bonus.c \
					animations_bonus.c \
					door_bonus.c

HEADERFILES			= $(DIR_HEADERS)cub3d.h
HEADERFILES_BONUS	= $(DIR_HEADERS_BONUS)cub3d_bonus.h

OBJS			=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS))
OBJS_BONUS		=	$(patsubst %.c, $(DIR_BUILD_BONUS)%.o, $(SRCS_BONUS))
SRCS			=	$(addprefix $(DIR_SRCS),$(SRC_FILE))
SRCS_BONUS		=	$(addprefix $(DIR_SRCS_BONUS),$(SRC_FILE_BONUS))

FLAGS		=	-Wall -Werror -Wextra
MLX_FLAGS	=	-lXext -lX11 -lm -lz

CC = cc

.PHONY: all
all: mlx libft $(NAME)

.PHONY: bonus
bonus: mlx libft $(NAME_BONUS)

$(NAME): $(OBJS) $(DIR_LIBFT)libft.a
			$(CC) $(OBJS) $(MLX_FLAGS) $(DIR_MLX)libmlx.a $(DIR_LIBFT)libft.a -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(DIR_LIBFT)libft.a
			$(CC) $(OBJS_BONUS) $(MLX_FLAGS) $(DIR_MLX)libmlx.a $(DIR_LIBFT)libft.a -o $(NAME_BONUS)

$(DIR_BUILD)%.o: %.c $(HEADERFILES) Makefile
				mkdir -p $(shell dirname $@)
				$(CC) $(FLAGS) -I/usr/include -Iminilibx-linux -c $< -o $@

$(DIR_BUILD_BONUS)%.o: %.c $(HEADERFILES_BONUS) Makefile
				mkdir -p $(shell dirname $@)
				$(CC) $(FLAGS) -I/usr/include -Iminilibx-linux -c $< -o $@

.PHONY: mlx
mlx:
		${MAKE} -C $(DIR_MLX)

.PHONY: libft
libft:
		${MAKE} -C $(DIR_LIBFT)

.PHONY: clean
clean:
	${MAKE} -C $(DIR_LIBFT) clean
	${MAKE} -C $(DIR_MLX) clean
	rm -rf $(DIR_BUILD)

.PHONY: clean_bonus
clean_bonus:
	${MAKE} -C $(DIR_LIBFT) clean
	${MAKE} -C $(DIR_MLX) clean
	rm -rf $(DIR_BUILD_BONUS)

.PHONY: fclean
fclean: clean
		$(MAKE) -C $(DIR_LIBFT) fclean
		rm -rf $(NAME)

.PHONY: fclean_bonus
fclean_bonus: clean_bonus
		$(MAKE) -C $(DIR_LIBFT) fclean
		rm -rf $(NAME_BONUS)

.PHONY: re
re: fclean
	$(MAKE) all

.PHONY: re_bonus
re_bonus: fclean_bonus
	$(MAKE) bonus
