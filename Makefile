NAME = libftprintf.a

LIB_OBJECTS = ft_printf.o ft_printf_funciones.o

CC = gcc
CFLAGS = -Wall -Wextra 

all: $(NAME)

$(LIB_OBJECTS): %.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIB_OBJECTS)
	ar rcs $(NAME) $(LIB_OBJECTS)

clean:
	rm -f $(LIB_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re