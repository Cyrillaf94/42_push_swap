CC := cc
CFLAGS := -g3 -Wall -Wextra -Werror

NAME := test_suite
SOURCE_FILES := ../src/*/*.c lists.c index.c main.c

all: run clean

$(NAME): $(SOURCE_FILES)
	 cc -o $(NAME) -I ../includes $(SOURCE_FILES) -L ../lib -lftprintf -lft -lcunit

run: $(NAME)
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         ./$(NAME)

clean:
	rm $(NAME)
