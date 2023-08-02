NAME =	get_next_line.a
HEADER =	get_next_line.h
SRC = 	get_next_line.c\
		get_next_line_utils.c

OBJ = $(SRC:.c=.o)
DEP	= $($(basename $(OBJ)))
CC = cc
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=42

$(NAME):: $(OBJ) $(HEADER)
	ar -crs $(NAME) $(OBJ)

-include $(DEP)

all: $(NAME)

c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re .c.o