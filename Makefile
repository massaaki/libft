# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 22:39:04 by mmassaak          #+#    #+#              #
#    Updated: 2021/05/16 22:51:32 by mmassaak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_strlen.c 
OUT_FILES = $(SRC:.c=.o) # substitute .c to .o to all SRC
NAME = libft.a
FLAGS = -Wall -Werror -Wextra

all:
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OUT_FILES)
	ranlib $(NAME)

clean:
	rm $(OUT_FILES)

fclean:
	rm $(NAME)
