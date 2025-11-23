NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_isascii.c ft_memcpy.c ft_strlcat.c ft_strrchr.c \
      ft_bzero.c ft_isdigit.c ft_memmove.c ft_strlcpy.c ft_tolower.c \
      ft_calloc.c ft_isprint.c ft_memset.c ft_strlen.c ft_toupper.c \
      ft_isalnum.c ft_memchr.c ft_strchr.c ft_strncmp.c \
      ft_isalpha.c ft_memcmp.c ft_strdup.c ft_strnstr.c ft_substr.c \
	  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	  ft_putnbr_fd.c

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
            ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
            ft_lstmap.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

TEST = test_libft_full.c
TEST_BIN = test_libft

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)


%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(TEST_BIN)

re: fclean all

test: $(NAME)
ifneq ("$(wildcard $(TEST))","")
	$(CC) $(CFLAGS) $(TEST) $(NAME) -o $(TEST_BIN)
	./$(TEST_BIN)
else
	@echo "No hay archivo de test disponible."
endif

.PHONY: all clean fclean re test