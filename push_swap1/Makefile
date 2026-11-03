NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
       param_parser.c \
       input_parser.c \
       input_parser_utils.c \
       stack_utils.c \
       rank_stack.c \
       ft_printf.c \
       disorder.c \
       push_ops.c \
       swap_ops.c \
       rotate_ops.c \
       reverse_rotate_ops.c \
       sort_small.c \
       sort_three.c \
       sort_simple.c \
       sort_medium.c \
       sort_complex.c \
       sort_utils.c \
       benchmark.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
