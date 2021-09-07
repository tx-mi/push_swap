NAME = push_swap

# LIB
PATH_LIB = ./libft/
LIBFT = ./libft/libft.a

# Headers
HEADER = ./includes/push_swap.h
HEADER_INC = -I./includes/

# Sources
PATH_TO_SRCS = sources/
SRC = 	operations.c parse.c push_swap.c quick_sort.c \
		stack_control.c stack_functions.c utils.c
SRCS = $(addprefix $(PATH_TO_SRCS), $(SRC))

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
