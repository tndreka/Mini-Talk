
CC = cc

CFLAGS = -Wall -Wextra -Werror -I./ft_printf

PRINTFDIR = ft_printf/

INCLUDE =  -L ./ft_printf -lftprintf 

CLIENT = client

SERVER = server

SRC_CLIENT = client.c

SRC_SERVER = server.c

OBJS_CLIENT = ${SRC_CLIENT:.c=.o}

OBJS_SERVER = ${SRC_SERVER:.c=.o}

all: ${CLIENT} ${SERVER}

${CLIENT}: ${OBJS_CLIENT}
	@make -sC ${PRINTFDIR}
	@${CC} ${CFLAGS} -o ${CLIENT} ${OBJS_CLIENT} ${INCLUDE} -g

${CLIENT}: ${OBJS_SERVER}
	@make -sC ${PRINTFDIR}
	@${CC} ${CFLAGS} -o ${SERVER} ${OBJS_SERVER} ${INCLUDE} -g

clean:
	@rm -f ${OBJS}
	@cd ${PRINTFDIR} && ${MAKE} clean

fclean:
	${MAKE} clean
	@rm -f ${NAME}
	@cd ${PRINTFDIR} && ${MAKE} fclean

re: fclean all

.PHONY: all clean fclean re