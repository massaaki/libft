# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 22:39:04 by mmassaak          #+#    #+#              #
#    Updated: 2021/05/23 18:22:25 by mmassaak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_strlen.c \
	  ft_bzero.c \
	  ft_memset.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlcpy.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strnstr.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_calloc.c \
	  ft_strdup.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c
OUT_FILES = $(SRC:.c=.o)# substitute .c to .o to all SRC
NAME = libft.a
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): *.c
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OUT_FILES)
	ranlib $(NAME)

clean:
	$(RM) $(OUT_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test:
	make m -C ./libft_tests
