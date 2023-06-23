NAME =	libftprintf.a
HEADER =	libftprintf.h
SRC = 	ft_printf.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putnbr_base.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):: $(OBJ) $(HEADER)
	ar -crs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re .c.o