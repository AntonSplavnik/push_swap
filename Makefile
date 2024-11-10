# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 20:36:45 by asplavni          #+#    #+#              #
#    Updated: 2024/11/10 19:45:10 by antonsplavn      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Source and object files
SRC = $(SRC_DIR)/fill_array.c $(SRC_DIR)/ft_split.c $(SRC_DIR)/init.c \
      $(SRC_DIR)/main.c $(SRC_DIR)/number_counter.c $(SRC_DIR)/parsing.c \
      $(SRC_DIR)/utility_functions.c $(SRC_DIR)/swap.c $(SRC_DIR)/rotate.c \
	  $(SRC_DIR)/reverse_rotate.c/ $(SRC_DIR)/push.c $(SRC_DIR)/sort_check.c
OBJ = $(OBJ_DIR)/fill_array.o $(OBJ_DIR)/ft_split.o $(OBJ_DIR)/init.o \
      $(OBJ_DIR)/main.o $(OBJ_DIR)/number_counter.o $(OBJ_DIR)/parsing.o \
      $(OBJ_DIR)/utility_functions.o $(OBJ_DIR)/swap.o $(OBJ_DIR)/rotate.o \
	  $(OBJ_DIR)/reverse_rotate.o $(OBJ_DIR)/push.o $(OBJ_DIR)/sort_check.o

# Header file
HEADER = $(INC_DIR)/push_swap.h

# Output executable name
TARGET = push_swap

# Default rule
all: $(TARGET)

# Rule to build the final executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# Rule to create object files (.o) from source files (.c)
# Ensures that the obj/ directory exists
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files only
clean:
	rm -f $(OBJ)

# Full clean: removes object files and executable
fclean: clean
	rm -f $(TARGET)

# Rebuild the project from scratch
re: fclean all

# Phony targets
.PHONY: all clean fclean re
