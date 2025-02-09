NAME = libftprintf.a

LIB_OBJECTS = ft_printf.o ft_printf_funciones.o

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIB_OBJECTS): %.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIB_OBJECTS)
	ar rcs $(NAME) $(LIB_OBJECTS)

clean:
	rm -rf $(LIB_OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re