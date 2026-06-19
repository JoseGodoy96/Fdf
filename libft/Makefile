# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 15:31:07 by jgodoy-m          #+#    #+#              #
#    Updated: 2025/08/19 15:53:52 by jgodoy-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library file name
NAME = libft

# Compiler and compilation flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

# Define directories
INCLUDE_DIR = ./include
SRC_DIR = ./src

# Source files and object files
SRC = 	$(SRC_DIR)/ft_isalpha.c \
		$(SRC_DIR)/ft_isdigit.c \
		$(SRC_DIR)/ft_isalnum.c \
		$(SRC_DIR)/ft_isascii.c \
		$(SRC_DIR)/ft_isprint.c \
		$(SRC_DIR)/ft_strlen.c \
		$(SRC_DIR)/ft_memset.c \
		$(SRC_DIR)/ft_bzero.c \
		$(SRC_DIR)/ft_memcpy.c \
		$(SRC_DIR)/ft_memmove.c \
		$(SRC_DIR)/ft_strlcpy.c \
		$(SRC_DIR)/ft_strlcat.c \
		$(SRC_DIR)/ft_toupper.c \
		$(SRC_DIR)/ft_tolower.c \
		$(SRC_DIR)/ft_strchr.c \
		$(SRC_DIR)/ft_strrchr.c \
		$(SRC_DIR)/ft_strncmp.c \
		$(SRC_DIR)/ft_memchr.c \
		$(SRC_DIR)/ft_memcmp.c \
		$(SRC_DIR)/ft_strnstr.c \
		$(SRC_DIR)/ft_atoi.c \
		$(SRC_DIR)/ft_calloc.c \
		$(SRC_DIR)/ft_strdup.c \
		$(SRC_DIR)/ft_substr.c \
		$(SRC_DIR)/ft_strjoin.c \
		$(SRC_DIR)/ft_strtrim.c \
		$(SRC_DIR)/ft_split.c \
		$(SRC_DIR)/ft_itoa.c \
		$(SRC_DIR)/ft_strmapi.c \
		$(SRC_DIR)/ft_striteri.c \
		$(SRC_DIR)/ft_putchar_fd.c \
		$(SRC_DIR)/ft_putstr_fd.c \
		$(SRC_DIR)/ft_putendl_fd.c \
		$(SRC_DIR)/ft_putnbr_fd.c 
BONUSSRC = 	$(SRC_DIR)/ft_lstnew_bonus.c \
		$(SRC_DIR)/ft_lstadd_front_bonus.c \
		$(SRC_DIR)/ft_lstsize_bonus.c \
		$(SRC_DIR)/ft_lstlast_bonus.c \
		$(SRC_DIR)/ft_lstadd_back_bonus.c \
		$(SRC_DIR)/ft_lstdelone_bonus.c \
		$(SRC_DIR)/ft_lstclear_bonus.c \
		$(SRC_DIR)/ft_lstiter_bonus.c
OBJ = $(SRC:.c=.o)

# Header file
INCLUDE = $(INCLUDE_DIR)/libft.h

# Create libraries and delete files
AR = ar rcs
RM = rm -f

# Indicates that the following rules are not real files
.PHONY: all bonus clean fclean re

# Rule that compiles everything by default
all: $(NAME)

# Rule to create the library
$(NAME): $(OBJ)
	$(AR) $@ $^

# Convert .c files to .o
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<

# Rule for compiling bonus functions
bonus: $(OBJ) $(BONUSOBJ)
	$(AR) $(NAME) $^

# Rule to delete all created object files
clean:
	$(RM) $(OBJ) $(BONUSOBJ)

# Delete all .o and .a files
fclean: clean
	$(RM) $(NAME)

re: fclean all
