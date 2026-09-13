NAME = libftprintf.a
SRC = ft_printf.c ft_printf_utils.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re