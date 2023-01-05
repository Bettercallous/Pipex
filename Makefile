# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 05:51:20 by oubelhaj          #+#    #+#              #
#    Updated: 2023/01/04 05:51:22 by oubelhaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = pipex.c utils.c ft_split.c ft_strjoin.c

NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}:
	@${CC} ${CFLAGS} ${SRC} -o ${NAME}
	@echo "\033[1;33mpipex: pipex program compiled successfully!\033[0m"

clean:
	@rm -rf *.o
	@echo "\033[1;31mpipex: Removed all .o files!\033[0m"

fclean: clean
	@rm -rf ${NAME}
	@echo "\033[1;31mpipex: Removed pipex program!\033[0m"

re: fclean all
	@echo "\033[1;32mpipex: Re-creating pipex program!\033[0m"
