CC = cc
NAME = client
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c	\
	   util.c	\

OBJS = ${SRCS:.c=.o}

all : ${NAME}

$(NAME) : ${OBJS}
	${CC} -o ${NAME} ${CFLAG} ${SRCS}


clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

.PHONY : all compile clean fclean bonus re

re : fclean all
