# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 05:51:20 by oubelhaj          #+#    #+#              #
#    Updated: 2023/01/10 06:59:40 by oubelhaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = main.c utils.c ft_split.c ft_strjoin.c utils2.c

NAME = pipex

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

.c.o	:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all		:	$(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;32m- Pipex program compiled!"

clean	:
	@rm -rf $(OBJS)
	@echo "\033[1;31m- Object files removed!"

fclean	:	clean
	@rm -rf $(NAME)
	@echo "\033[1;31m- Pipex program removed!"

re : fclean all

.PHONY : all clean fclean re