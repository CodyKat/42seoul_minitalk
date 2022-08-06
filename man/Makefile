CC = cc
NAME_SERVER = ./server/server
NAME_CLIENT = ./client/client
NAME = ${NAME_SERVER} ${NAME_CLIENT}

all : ${NAME}

$(NAME) :
	make -C ./server/ all
	make -C ./client/ all

clean :
	make -C ./server/ clean
	make -C ./client/ clean

fclean :
	make -C ./server/ fclean
	make -C ./client/ fclean

.PHONY : all compile clean fclean bonus re

re : fclean all
