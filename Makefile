# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 22:39:04 by mmassaak          #+#    #+#              #
#    Updated: 2021/05/17 23:41:59 by mmassaak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_strlen.c ft_bzero.c ft_memset.c ft_memcpy.c
OUT_FILES = $(SRC:.c=.o)# substitute .c to .o to all SRC
NAME = libft.a
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OUT_FILES)
	ranlib $(NAME)

clean:
	rm -f $(OUT_FILES)

fclean:
	rm -f $(NAME)

re:
	rm -f $(OUT_FILES)
	rm -f $(NAME)
