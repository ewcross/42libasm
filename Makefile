# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/31 10:59:20 by ecross            #+#    #+#              #
#    Updated: 2020/03/31 11:56:38 by ecross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS = 	ft_strlen.s \
	ft_strcpy.s \
	ft_strcmp.s \
	ft_write.s \
	ft_read.s \
	ft_strdup.s

TESTER = test_main.c

RM = rm -f

NASM = nasm

NASM_FLAGS = -f macho64

GCC = gcc

C_FLAGS = -Wall -Wextra -Werror

LD = ld

LD_FLAGS = -lSystem

%.o:		%.s
	${NASM} ${NASM_FLAGS} $<

OBJS = ${SRCS:.s=.o}

${NAME}:	${OBJS}
	ar surc ${NAME} ${OBJS}

all:		${NAME}

test:		${NAME}
	${GCC} ${CFLAGS} -L. -lasm ${TESTER}

clean:
	${RM} ${OBJS} ${TESTER:.c=.o}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re
