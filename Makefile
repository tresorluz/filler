# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tluzing <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/08 10:08:26 by tluzing           #+#    #+#              #
#    Updated: 2018/08/14 16:27:25 by tluzing          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tresor.filler

CC = gcc -o

FLAGS = -Wall -Wextra -Werror

INC = -I ./includes/

LIB = ./libft/

SRC = ./srcs/*.c

RM = rm -rf

$(NAME):
	@make -C $(LIB)
	@$(CC) $(NAME) $(FLAGS) $(SRC) $(INC) -L libft/ -lft
	@echo "-- Player Compiled Successfully --"

all: $(NAME)

clean:
	@make clean -C $(LIB)

fclean:
	@make fclean -C $(LIB)
	@$(RM) $(NAME)
	@echo "-- Player Cleaned --"

re: fclean all
