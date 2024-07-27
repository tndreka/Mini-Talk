
CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTFDIR = ft_printf/
CLIENT = client
SERVER = server
SRC = server.c client.c
INCLUDE =  -L ./ft__printf_p -lftprintf
OBJS = ${SRC:.c=.o}
all: ${NAME}
${NAME}: ${OBJS}
	@make -sC ${LIBFTDIR}
	@make -sC ${PRINTFDIR}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${INCLUDE} -g
clean:
	@rm -f ${OBJS}
	@cd ${LIBFTDIR} && ${MAKE} clean
	@cd ${PRINTFDIR} && ${MAKE} clean
fclean:
	${MAKE} clean
	@rm -f ${NAME}
	@cd ${LIBFTDIR} && ${MAKE} fclean
	@cd ${PRINTFDIR} && ${MAKE} fclean
re: fclean all
.PHONY: all clean fclean re