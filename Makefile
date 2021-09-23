NAME = push_swap

# LIB
PATH_LIB = ./libft/
LIBFT = ./libft/libft.a

# Headers
HEADER = ./includes/push_swap.h
HEADER_INC = -I./includes/

# Sources
SRC = $(shell ls ./sources/*.c) $(shell ls ./sources/API_operations/*.c)

# Objects
OBJS = $(patsubst %.c, %.o, $(SRC))

# Commands
CC	= gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $(HEADER_INC) $< -o $@

all: run_lib $(NAME) 

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(HEADER_INC) $(LIBFT) -o $(NAME) $(OBJS)

run_lib:
	make -C libft/

clean:
	$(RM) $(OBJS)
	make -C libft/ clean

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
