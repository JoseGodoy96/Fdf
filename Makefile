# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/12 13:04:48 by jgodoy-m          #+#    #+#              #
#    Updated: 2025/11/24 19:18:43 by jgodoy-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library file name
NAME = fdf

# Compiler and compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include -I$(GNL_DIR)/include -g

# Define directories
INCLUDE_DIR = ./include
SRC_DIR = ./src
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux
GNL_DIR = ./gnl

# Source files and object files
SRC = 	$(SRC_DIR)/algorithm.c \
		$(SRC_DIR)/camera.c \
		$(SRC_DIR)/draw.c \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/parsing_map.c \
		$(SRC_DIR)/parsing_init.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/hooks.c \
		$(SRC_DIR)/projection.c

OBJ = $(SRC:.c=.o)

# Libraries
LIBFT = $(LIBFT_DIR)/libft
MLX = $(MLX_DIR)/libmlx.a
GNL_LIB = $(GNL_DIR)/gnl

# Create libraries and delete files
AR = ar rcs
RM = rm -f

# Indicates that the following rules are not real files
.PHONY: all clean fclean re 

# Rule that compiles everything by default
all: $(NAME)

# Rule to create the fdf
$(NAME): $(LIBFT) $(GNL_LIB) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(GNL_LIB) $(LIBFT) $(MLX) -lXext -lX11 -lm -o $(NAME)

# Rule to build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to build mlx
$(MLX):
	$(MAKE) -C $(MLX_DIR)

# Rule to build gnl (expects gnl/Makefile to produce libgnl.a)
$(GNL_LIB):
	$(MAKE) -C $(GNL_DIR)

# Convert .c files to .o
%.o: %.c $(INCLUDE_DIR)/fdf.h
	$(CC) $(CFLAGS) -c $< -o $@


# Rule to delete all created object files
clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean

# Delete all .o and .a files
fclean: clean
	$(RM) $(NAME) $(LIBFT) $(MLX) $(GNL_LIB)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean

re: fclean all
