NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putelse.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(TEST_BIN)

re: fclean all

.PHONY: all clean fclean re test