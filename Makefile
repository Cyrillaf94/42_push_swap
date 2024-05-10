CC := cc
CFLAGS := -g3 -Wall -Wextra -Werror

# Directories
SRC_PATH := src
INC_PATH := includes
LIB_PATH := lib
OBJ_PATH := obj
BIN_PATH := .

# Source directories
PARSING_DIR := parsing
SORTING_DIR := sorting
UTILS_DIR := utils
SOURCE_DIRS := $(PARSING_DIR) $(SORTING_DIR) $(UTILS_DIR)
OBJ_PATHS := $(addprefix $(OBJ_PATH)/, $(SOURCE_DIRS))

# Source files
PARSING_FILES := parse_list.c
SORTING_FILES := instructions.c  sort.c
UTILS_FILES := helpers.c node_t.c stdlib.c

# Concatenating source files with directories
PARSING_SRCS := $(addprefix $(PARSING_DIR)/, $(PARSING_FILES))
SORTING_SRCS := $(addprefix $(SORTING_DIR)/, $(SORTING_FILES))
UTILS_SRCS := $(addprefix $(UTILS_DIR)/, $(UTILS_FILES))
MAIN_SRC := main.c

# Creating object file paths
PARSING_OBJS := $(addprefix $(PARSING_DIR)/, $(PARSING_FILES:.c=.o))
SORTING_OBJS := $(addprefix $(SORTING_DIR)/, $(SORTING_FILES:.c=.o))
UTILS_OBJS := $(addprefix $(UTILS_DIR)/, $(UTILS_FILES:.c=.o))
MAIN_OBJ := $(MAIN_SRC:.c=.o)

# Concatenating all object files
OBJS := $(addprefix $(OBJ_PATH)/, $(PARSING_OBJS) $(SORTING_OBJS) $(UTILS_OBJS) $(MAIN_OBJ))

# Output executable
NAME = push_swap

# Rules
all: $(NAME)

debug: $(OBJS)
	$(CC) $(CFLAGS) -g -o $(BIN_PATH)/$(NAME) $^ -L$(LIB_PATH) -lftprintf -lft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN_PATH)/$@ $^ -L$(LIB_PATH) -lftprintf -lft

# Compilation rules for each source file
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATHS)
	$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@

# Create object directory if it doesn't exist
$(OBJ_PATHS):
	mkdir -p $(OBJ_PATH)
	mkdir -p $(OBJ_PATHS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(BIN_PATH)/$(NAME)

re: fclean all

.PHONY: all clean fclean re
