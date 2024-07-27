CFLAGS = -Wall -Werror -Wextra 
SRC = ft_printf.c ft_format_printer.c ft_print_char.c ft_print_string.c ft_print_digit.c\
		ft_print_pointer.c ft_print_dec_int.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

%.o: %.cc
	cc -c $< -o $@ ${CFLAGS}

clean :
	rm -f ${OBJ}
	rm -f ${NAME}

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re