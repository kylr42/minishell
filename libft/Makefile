CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRCS =	ft_atoi.c ft_bzero.c \
		ft_memcpy.c ft_memccpy.c \
		ft_memcmp.c ft_memmove.c \
		ft_memchr.c ft_strlen.c \
		ft_isalpha.c ft_isdigit.c \
		ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c \
		ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c \
		ft_strncmp.c ft_strnstr.c \
		ft_calloc.c ft_strdup.c \
		ft_strlcpy.c ft_itoa.c \
		ft_strmapi.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_strlcpy.c \
		ft_strlcat.c ft_split.c ft_memset.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
        ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
        ft_lstclear.c ft_lstiter.c

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS:.c=.o}
DEPS = libft.h

all: ${NAME}

.c.o: ${SRCS}
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf '\033[0;34mObject $@ [\033[0;32m✔\033[0;34m]\n\033[0m'

${NAME}: ${OBJS} ${DEPS} ${BONUS_OBJS}
	@ar -rc ${NAME} ${OBJS} ${BONUS_OBJS}
	@ranlib ${NAME}
	@printf '\033[1;32mLibft compile success!\n\033[0m'

clean:
	@rm -rf $(OBJS) ${BONUS_OBJS}
	@printf '\033[1;35m%s\n\033[0m' "Clean Libft"

fclean: clean
	@rm -rf ${NAME}
	@printf '\033[1;35m%s\n\033[0m' "Fclean Libft"

re: fclean all

.PHONY:	all clean fclean re bonus
