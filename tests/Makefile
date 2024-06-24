CC := cc
CFLAGS := -g3 -Wall -Wextra -Werror

NAME := test_suite
SOURCE_FILES := ../src/*/*.c lists.c instructions.c index.c sort.c main.c parsing.c

all: run clean

compile: $(NAME)

$(NAME): $(SOURCE_FILES)
	 cc -g -o $(NAME) -I ../includes $(SOURCE_FILES) -L ../lib -lftprintf -lft -lcunit

run: $(NAME)
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         ./$(NAME)

clean:
	rm $(NAME)
