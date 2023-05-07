# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 13:49:45 by mapfenni          #+#    #+#              #
#    Updated: 2023/05/07 14:15:19 by mapfenni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

EX_FUN = ./

SRCS = 

CFLAGS += -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS} ${BONUS}

fclean: clean
	rm -f ${NAME}

re: fclean all