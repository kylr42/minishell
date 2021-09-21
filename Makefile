CC=gcc
CFLAGS=-Wall -Wextra -Werror

NAME = minishell


INC = .
SRCS_DIR = ./source/
OBJS_DIR = ./objects/

SRCS = echo.c
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))


# LIBFT CONFIG
LIB_DIR = ./libft/
LIBFT = libft/libft.a
# LIBFT CONFIG


all: ${NAME}

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -I$(LIB_DIR) -I$(INC) -c $< -o $@

${NAME}: $(OBJS_DIR) $(OBJS) ${LIBFT}
	@$(CC) ${CFLAGS} ${LIBFT} ${OBJS} -I$(LIB_DIR) main.c -o ${NAME}
	@printf '\033[1;32m${NAME} compile success!\n\033[0m'

${LIBFT}:
	@make -C $(LIB_DIR)

clean:
	@rm -rf $(BUILDDIR)
	@make clean -C $(LIB_DIR)
	@printf '\033[1;35mDelete objects success!\n\033[0m'


fclean:
	@make fclean -C $(LIB_DIR)
	@rm -rf ${NAME}
	@printf '\033[1;35mDelete ${NAME} success!\n\033[0m'

re: fclean all

.PHONY:	all clean fclean re