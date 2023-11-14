# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 12:18:48 by clbernar          #+#    #+#              #
#    Updated: 2023/11/14 16:16:46 by clbernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## MAIN VARIABLES


CC = 			cc

CFLAGS = 		-g3 -Wall -Wextra -Werror

RM =			rm -f

RM_RF =			rm -rf

## SOURCES AND LIBS

SRC_DIR = 		./src

SRCS =			$(SRC_DIR)/main.c \
				$(SRC_DIR)/pre_parsing.c\
				$(SRC_DIR)/utils_1.c\
				$(SRC_DIR)/utils_2.c\
				$(SRC_DIR)/parsing_texture_1.c\
				$(SRC_DIR)/parsing_texture_2.c\
				$(SRC_DIR)/parsing_map_1.c\
				$(SRC_DIR)/parsing_map_2.c\
				$(SRC_DIR)/parsing_map_3.c\
				$(SRC_DIR)/init_struct.c\
				$(SRC_DIR)/clear.c\
				$(SRC_DIR)/window.c\

LIBFTDIR = 		./libft

LIBFT =			$(LIBFTDIR)/libft.a

LIBFT_FLAGS = 	-L$(LIBFTDIR) -lft

#LREADLINE_FLAGS = -lreadline

## OBJECTS

OBJ_DIR =		./obj

OBJS = 			$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

## HEADERS

HDIR = 			./inc

HD = 			$(HDIR)/minishell.h \
				$(LIBFTDIR)/inc/libft.h \
				$(LIBFTDIR)/inc/get_next_line_bonus.h \
				$(LIBFTDIR)/inc/ft_printf.h \

INC_HD =		-I $(HDIR) -I $(LIBFTDIR)/inc

## RULES

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJS)
				$(CC) $(CFLAGS) $(INC_HD) $(OBJS) $(LIBFT_FLAGS) $(LREADLINE_FLAGS) -o $@

$(OBJS):		$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HD)
				mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) $(INC_HD) -c $< -o $@

$(LIBFT):
				make -C $(LIBFTDIR)

clean:
				$(RM_RF) $(OBJ_DIR)
				make clean -C $(LIBFTDIR)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(LIBFT)

re:				fclean all

.PHONY: 		all clean fclean re
