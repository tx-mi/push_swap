NAME = push_swap

# LIB
PATH_LIB = ./libft/
LIBFT = ./libft/libft.a

# Headers
HEADER = ./includes/push_swap.h
HEADER_INC = -I./includes/

# Sources
SRC = $(shell ls ./sources/*.c) 
UTILS = $(shell ls ./sources/utils/*.c) 
SRCS = $(SRC) $(UTILS)
# Commands
CC	= gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: run_lib $(NAME) 

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(HEADER_INC) $(SRCS) $(LIBFT) -o $@

run_lib:
	make -C libft/

clean:
	make -C libft/ clean

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
