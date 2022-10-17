NAME=libft.a
SRC= \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_calloc.c \
	ft_strlen.c \
	ft_strdup.c \
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
	ft_tolower.c
OBJS=${SRC:.c=.o}
FLAGS= -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	ar -rc ${NAME} ${OBJS}

ft_memset.o: ft_memset.c
	gcc ${FLAGS} -c ft_memset.c

ft_bzero.o: ft_bzero.c
	gcc ${FLAGS} -c ft_bzero.c

ft_memcpy.o: ft_memcpy.c
	gcc ${FLAGS} -c ft_memcpy.c

ft_memmove.o: ft_memmove.c
	gcc ${FLAGS} -c ft_memmove.c

ft_memchr.o: ft_memchr.c
	gcc ${FLAGS} -c ft_memchr.c

ft_memcmp.o: ft_memcmp.c
	gcc ${FLAGS} -c ft_memcmp.c

ft_calloc.o: ft_calloc.c
	gcc ${FLAGS} -c ft_calloc.c

ft_strlen.o: ft_strlen.c
	gcc ${FLAGS} -c ft_strlen.c

ft_strdup.o: ft_strdup.c
	gcc ${FLAGS} -c ft_strdup.c

ft_strlcpy.o: ft_strlcpy.c
	gcc ${FLAGS} -c ft_strlcpy.c

ft_strlcat.o: ft_strlcat.c
	gcc ${FLAGS} -c ft_strlcat.c

ft_strchr.o: ft_strchr.c
	gcc ${FLAGS} -c ft_strchr.c

ft_strrchr.o: ft_strrchr.c
	gcc ${FLAGS} -c ft_strrchr.c

ft_strnstr.o: ft_strnstr.c
	gcc ${FLAGS} -c ft_strnstr.c

ft_strncmp.o: ft_strncmp.c
	gcc ${FLAGS} -c ft_strncmp.c

ft_atoi.o: ft_atoi.c
	gcc ${FLAGS} -c ft_atoi.c

ft_isalpha.o: ft_isalpha.c
	gcc ${FLAGS} -c ft_isalpha.c

ft_isdigit.o: ft_isdigit.c
	gcc ${FLAGS} -c ft_isdigit.c

ft_isalnum.o: ft_isalnum.c
	gcc ${FLAGS} -c ft_isalnum.c

ft_isascii.o: ft_isascii.c
	gcc ${FLAGS} -c ft_isascii.c

ft_isprint.o: ft_isprint.c
	gcc ${FLAGS} -c ft_isprint.c

ft_toupper.o: ft_toupper.c
	gcc ${FLAGS} -c ft_toupper.c

ft_tolower.o: ft_tolower.c
	gcc ${FLAGS} -c ft_tolower.c

clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all