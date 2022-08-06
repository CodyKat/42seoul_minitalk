CC = cc
NAME = server
NAME_LIBFT = libft.a
LIBFT_DIR = ./libft/
CFLAGS = -Wall -Wextra -Werror
SRCS = main_bonus.c				\
	   ft_printf_bonus.c			\
	   ft_printf_mode_bonus.c		\
	   ft_printf_utils_bonus.c	\

OBJS = ${SRCS:.c=.o}

%.o:%.c
	$(CC) $(IFLAGS) $(CFLAGS) -o $@ -c $<

all : ${NAME}

$(NAME) :
	cd ${LIBFT_DIR}; make; cp ${NAME_LIBFT} ../; \
		cd ../; ${CC} -o ${NAME} ${CFLAGS} *.c ${NAME_LIBFT};

clean :
	rm -f ${OBJS} ${NAME_LIBFT}; cd libft; make clean

fclean : clean
	rm -f ${NAME}; cd libft; make fclean

.PHONY : all compile clean fclean bonus re

re : fclean all
