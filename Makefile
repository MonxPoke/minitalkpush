SRC = client.c helpers.c
SRCB = server.c helpers.c
OBJ = ${SRC:.c=.o}
OBJB = ${SRCB:.c=.o}
CC = gcc
NAME = client
BNAME = server
RM = rm -f
CFLAGS = -Wall -Wextra -Werror


all : $(NAME) $(BNAME)

$(NAME) : $(OBJ)
	gcc -Wall -Wextra -Werror -g $(OBJ) -o $(NAME)
$(BNAME) : $(OBJB)
	gcc -Wall -Wextra -Werror -g $(OBJB) -o $(BNAME)
clean :
	$(RM) $(OBJ) $(OBJB)
fclean : clean
	$(RM) $(NAME) $(BNAME)
re: fclean all
	
.PHONY : all clean fclean re