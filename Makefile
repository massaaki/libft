SRC = ft_strlen.c ft_bzero.c ft_memset.c ft_memcpy.c \
	  ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	  ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	  ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
	  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
	  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	  ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c
SRC_OBJECTS = $(SRC:.c=.o)
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	  ft_lstmap.c
BONUS_OBJECTS = $(BONUS:.c=.o)
NAME = libft.a
FLAGS = -Wall -Werror -Wextra
RM = rm -rf
CC = gcc
LIBFLAGS = rcs
MAKELIB = ar ${LIBFLAGS}

all: ${NAME}

${NAME}: ${SRC_OBJECTS}
	${MAKELIB} ${NAME} ${SRC_OBJECTS}

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@ 
	
bonus: ${BONUS_OBJECTS} ${NAME}
	${MAKELIB} ${NAME} ${BONUS_OBJECTS}

clean:
	${RM} ${SRC_OBJECTS} ${BONUS_OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
