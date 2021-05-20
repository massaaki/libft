# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 22:39:04 by mmassaak          #+#    #+#              #
#    Updated: 2021/05/19 23:10:36 by mmassaak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_strlen.c \
	  ft_bzero.c \
	  ft_memset.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c
OUT_FILES = $(SRC:.c=.o)# substitute .c to .o to all SRC
NAME = libft.a
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OUT_FILES)
	ranlib $(NAME)

clean:
	$(RM) $(OUT_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all
