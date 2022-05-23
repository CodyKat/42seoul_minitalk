CC = cc
NAME = ./client/client ./server/server
CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

$(NAME) :
	cd server; make; cd ..;	\
		cd client; make;

clean :
	cd server; make clean; cd ..;	\
		cd client; make clean;

fclean :
	cd server; make fclean; cd ..;	\
		cd client; make fclean;

.PHONY : all compile clean fclean bonus re

re : fclean all
