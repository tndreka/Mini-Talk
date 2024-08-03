
CC = cc

CFLAGS = -Wall -Wextra -Werror -I./ft_printf

PRINTFDIR = ft_printf/

INCLUDE =  -L ./ft_printf -lftprintf 

CLIENT = client

SERVER = server

SRC_CLIENT = client.c utils.c

SRC_SERVER = server.c utils.c

OBJS_CLIENT = ${SRC_CLIENT:.c=.o}

OBJS_SERVER = ${SRC_SERVER:.c=.o}

all: ${CLIENT} ${SERVER}

${CLIENT}: ${OBJS_CLIENT}
	@make -sC ${PRINTFDIR}
	@${CC} ${CFLAGS} -o ${CLIENT} ${OBJS_CLIENT} ${INCLUDE} -g

${SERVER}: ${OBJS_SERVER}
	@make -sC ${PRINTFDIR}
	@${CC} ${CFLAGS} -o ${SERVER} ${OBJS_SERVER} ${INCLUDE} -g

clean:
	@rm -f ${OBJS_CLIENT} ${OBJS_SERVER}
	@cd ${PRINTFDIR} && ${MAKE} clean

fclean:
	${MAKE} clean
	@rm -f ${CLIENT} ${SERVER}
	@cd ${PRINTFDIR} && ${MAKE} fclean

re: fclean all

.PHONY: all clean fclean re