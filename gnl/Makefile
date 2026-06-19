# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 21:57:47 by jgodoy-m          #+#    #+#              #
#    Updated: 2025/09/05 21:58:00 by jgodoy-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library file name
NAME = gnl

# Compiler and compilation flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

# Define directories
INCLUDE_DIR = ./include
SRC_DIR = ./src

# Source files and object files
SRC = 	$(SRC_DIR)/get_next_line_utils.c \
		$(SRC_DIR)/get_next_line.c

OBJ = $(SRC:.c=.o)

# Header file
INCLUDE = $(INCLUDE_DIR)/get_next_line.h

# Create libraries and delete files
AR = ar rcs
RM = rm -f

# Indicates that the following rules are not real files
.PHONY: all clean fclean re 

# Rule that compiles everything by default
all: $(NAME)

# Rule to create the gnl
$(NAME): $(OBJ)
	$(AR) $@ $^

# Convert .c files to .o
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<

# Rule to delete all created object files
clean:
	$(RM) $(OBJ)

# Delete all .o and .a files
fclean: clean
	$(RM) $(NAME)

re: fclean all
