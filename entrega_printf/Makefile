NAME =	libftprintf.a
HEADER =	libftprintf.h
SRC = 	ft_printf.c\
		ft_putformat.c\
		ft_putnbr_base.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra

$(NAME):: $(OBJ) $(HEADER)
	ar -crs $(NAME) $(OBJ)

all: $(NAME)

c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re .c.o