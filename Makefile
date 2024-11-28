# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 17:36:04 by asplavni          #+#    #+#              #
#    Updated: 2024/11/27 22:56:43 by asplavni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Subdirectories
ALGO_DIR = $(SRC_DIR)/algorithm
BONUS_DIR = $(SRC_DIR)/bonus
GNL_DIR = $(BONUS_DIR)/gnl
SHARED_DIR = $(SRC_DIR)/shared
INIT_DIR = $(SHARED_DIR)/init
OPERATIONS_DIR = $(SHARED_DIR)/operations
PARSING_DIR = $(SHARED_DIR)/parsing
SORT_CHECK_DIR = $(SHARED_DIR)/sort_check
UTILITY_DIR = $(SHARED_DIR)/utility

# Object subdirectories
ALGO_OBJ_DIR = $(OBJ_DIR)/algorithm
BONUS_OBJ_DIR = $(OBJ_DIR)/bonus
GNL_OBJ_DIR = $(BONUS_OBJ_DIR)/gnl
SHARED_OBJ_DIR = $(OBJ_DIR)/shared
INIT_OBJ_DIR = $(OBJ_DIR)/shared/init
OPERATIONS_OBJ_DIR = $(OBJ_DIR)/shared/operations
PARSING_OBJ_DIR = $(OBJ_DIR)/shared/parsing
SORT_CHECK_OBJ_DIR = $(OBJ_DIR)/shared/sort_check
UTILITY_OBJ_DIR = $(OBJ_DIR)/shared/utility

# Header files
HEADER_SHARED = $(INC_DIR)/shared.h
HEADER_GNL = $(INC_DIR)/get_next_line.h
HEADER_BONUS = $(INC_DIR)/checker.h

# Source files
ALGO_SRC = $(ALGO_DIR)/main.c $(ALGO_DIR)/sort_3.c $(ALGO_DIR)/sort_5.c \
           $(ALGO_DIR)/sort_average.c $(ALGO_DIR)/sort_torque.c $(ALGO_DIR)/sorting.c

BONUS_SRC = $(BONUS_DIR)/main.c

GNL_SRC = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

INIT_SRC = $(INIT_DIR)/init.c

OPERATIONS_SRC = $(OPERATIONS_DIR)/push.c $(OPERATIONS_DIR)/rotate.c \
                 $(OPERATIONS_DIR)/reverse_rotate.c $(OPERATIONS_DIR)/swap.c

PARSING_SRC = $(PARSING_DIR)/fill_array.c $(PARSING_DIR)/number_counter.c $(PARSING_DIR)/parsing.c

SORT_CHECK_SRC = $(SORT_CHECK_DIR)/quicksort.c $(SORT_CHECK_DIR)/sort_check.c

UTILITY_SRC = $(UTILITY_DIR)/ft_split.c $(UTILITY_DIR)/utility_functions.c

# Shared source files
SHARED_SRC = $(INIT_SRC) $(OPERATIONS_SRC) $(PARSING_SRC) $(SORT_CHECK_SRC) $(UTILITY_SRC)

# Object files
ALGO_OBJ = $(ALGO_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJ = $(BONUS_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
GNL_OBJ = $(GNL_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
SHARED_OBJ = $(SHARED_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Targets
MANDATORY_TARGET = push_swap
BONUS_TARGET = checker

# Default rule
all: $(MANDATORY_TARGET)

# Rule to build the mandatory executable
$(MANDATORY_TARGET): $(ALGO_OBJ) $(SHARED_OBJ)
	$(CC) $(CFLAGS) $(ALGO_OBJ) $(SHARED_OBJ) -o $(MANDATORY_TARGET)

# Rule to build the bonus executable
bonus: $(BONUS_OBJ) $(GNL_OBJ) $(SHARED_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(GNL_OBJ) $(SHARED_OBJ) -o $(BONUS_TARGET)

# Rule to create object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_SHARED) $(HEADER_GNL) $(HEADER_BONUS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(ALGO_OBJ) $(BONUS_OBJ) $(GNL_OBJ) $(SHARED_OBJ)

# Clean everything
fclean: clean
	rm -f $(MANDATORY_TARGET) $(BONUS_TARGET)

# Rebuild
re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus