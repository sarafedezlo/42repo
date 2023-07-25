NAME =	libftprintf.a
HEADER =	libftprintf.h
SRC = 	ft_printf.c\
		ft_putstr_char.c\
		ft_putnbr_base.c\
		ft_putformat.c

OBJ = $(SRC:.c=.o)
DEP	= $(addsuffix .d, $(basename $(OBJ)))
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