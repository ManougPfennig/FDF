# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 13:49:45 by mapfenni          #+#    #+#              #
#    Updated: 2023/05/07 16:24:08 by mapfenni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c fractol.c

OBJS = ${SRCS:.c=.o}

${NAME}: ${OBJS}
	make -C ./sources/ft_printf
	gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit \
	${OBJS} ./sources/ft_printf/libftprintf.a -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS} ${BONUS}
	make clean -C ./sources/ft_printf

fclean: clean
	rm -f ${NAME}
	make fclean -C ./sources/ft_printf

re: fclean all
	make fclean -C ./sources/ft_printf