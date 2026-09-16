NAME = libftprintf.a

CC = gcc
AR = ar rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utils.c ft_hub.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re