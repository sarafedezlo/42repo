NAME =	libftprintf.a
HEADER =	libftprintf.h
SRC = 	ft_printf.c\
		ft_putformat.c\
		ft_putnbr_base.c\
		ft_putchar.c

OBJ = $(SRC:.c=.o)
DEP	= $($(basename $(OBJ)))
CC = cc
CFLAGS = -Wall -Werror -Wextra

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