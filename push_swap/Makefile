NAME = push_swap
CC = CC
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
INCLUDE = -I include 

SRCS = 

OBJS = {SRCS:.c=.o}

all: {NAME}

%c: %o
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -c $< ${<:.c=.o}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re