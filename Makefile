# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 05:51:20 by oubelhaj          #+#    #+#              #
#    Updated: 2023/01/12 05:25:07 by oubelhaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = main.c utils.c ft_split.c ft_strjoin.c utils2.c

NAME = pipex

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o	:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all		:	$(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;32m- Pipex program compiled!\033[0m"

clean	:
	@rm -rf $(OBJS)
	@echo "\033[1;31m- Object files removed!\033[0m"

fclean	:	clean
	@rm -rf $(NAME)
	@echo "\033[1;31m- Pipex program removed!\033[0m"

re : fclean all

.PHONY : all clean fclean re
