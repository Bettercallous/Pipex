# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 05:51:20 by oubelhaj          #+#    #+#              #
#    Updated: 2023/01/05 18:25:56 by oubelhaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = pipex.c utils.c ft_split.c ft_strjoin.c

NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}:
	@${CC} ${CFLAGS} ${SRC} -o ${NAME}
	@echo "\033[1;32mPipex program compiled!"

clean:
	@rm -rf *.o
	@echo "\033[1;31mObject files removed!"

fclean: clean
	@rm -rf ${NAME}
	@echo "\033[1;31mPipex program removed!"

re: fclean all
