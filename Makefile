# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 22:39:04 by mmassaak          #+#    #+#              #
#    Updated: 2021/05/17 19:38:29 by mmassaak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_strlen.c ft_memset.c
OUT_FILES = $(SRC:.c=.o) # substitute .c to .o to all SRC
NAME = libft.a
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OUT_FILES)
	ranlib $(NAME)

clean:
	rm $(OUT_FILES)

fclean:
	rm $(NAME)

re:
	@echo "? xP"
