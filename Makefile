# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 12:18:48 by clbernar          #+#    #+#              #
#    Updated: 2023/11/06 17:09:21 by clbernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## MAIN VARIABLES

NAME =			cub3d

CC = 			cc

CFLAGS = 		-g3 -Wall -Wextra -Werror

RM =			rm -f

RM_RF =			rm -rf

## SOURCES AND LIBS

SRC_DIR = 		./src

SRCS =			$(SRC_DIR)/main.c \
				$(SRC_DIR)/pre_parsing.c\
				$(SRC_DIR)/utils_1.c\
				$(SRC_DIR)/parsing_texture_1.c\
				$(SRC_DIR)/parsing_texture_2.c\
				$(SRC_DIR)/init_struct.c\
				$(SRC_DIR)/clear.c\

LIBFTDIR = 		./libft

LIBFT =			$(LIBFTDIR)/libft.a

LIBFT_FLAGS = 	-L$(LIBFTDIR) -lft

MLX_DIR =		./minilibx-linux

MLX = 			$(MLX_DIR)/libmlx.a \
				$(MLX_DIR)/libmlx_Linux.a

MLX_FLAGS =		-L$(MLX_DIR) -lmlx -lX11 -lXext

## OBJECTS

OBJ_DIR =		./obj

OBJS = 			$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

## HEADERS

HDIR = 			./inc

HD = 			$(HDIR)/cub3d.h \
				$(LIBFTDIR)/inc/libft.h \
				$(LIBFTDIR)/inc/get_next_line_bonus.h \
				$(LIBFTDIR)/inc/ft_printf.h \
				$(MLX_DIR)/mlx.h \
				$(MLX_DIR)/mlx_int.h

INC_HD =		-I $(HDIR) -I $(LIBFTDIR)/inc -I $(MLX_DIR)

## RULES

all:			$(NAME)

$(NAME):		$(LIBFT) $(MLX) $(OBJS)
				$(CC) $(CFLAGS) $(INC_HD) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $@

$(OBJS):		$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HD)
				mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) $(INC_HD) -c $< -o $@

$(LIBFT):
				make -C $(LIBFTDIR)

$(MLX):
				make -C $(MLX_DIR)

clean:
				$(RM_RF) $(OBJ_DIR)
				make clean -C $(LIBFTDIR)
				make clean -C $(MLX_DIR)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(LIBFT)
				$(RM) $(MLX)

re:				fclean all

.PHONY: 		all clean fclean re
