NAME = libft.a
SRC = 	ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memset.c\
		ft_strlen.c\
		ft_memcpy.c\
		ft_memmove.c

OBJ = $(SRC:.c=.o)
CFLAGS += -Wall -Werror -Wextra -I./libft.h

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

all: $(NAME)

re: fclean all
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: add re clean fclean
