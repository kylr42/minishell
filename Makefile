CC=gcc
CFLAGS= -Wall -Wextra -Werror
RFLAGS= -lreadline -L ~/.brew/opt/readline/lib

NAME = minishell

INC = .
SRCS_DIR = ./sources/
OBJS_DIR = ./objects/

LIB_DIR = ./libft/
LIBFT = ${LIB_DIR}libft.a

SRCS_FILES = env_utils.c echo.c errors.c init.c loop.c lst.c parser.c parser_utils.c utils.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))


all: ${NAME}

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

${LIBFT}:
	@make -C $(LIB_DIR)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -I$(LIB_DIR) -I$(INC) -c $< -o $@
	@printf "\033[0;33mObject %-40.100s [\033[0;32m✔\033[0;33m]\r" $@

${NAME}: $(LIBFT) $(OBJS_DIR) $(OBJS) main.c
	@$(CC) ${CFLAGS} ${LIBFT} -I$(LIB_DIR) $(RFLAGS) ${OBJS} main.c -o ${NAME}
	@printf '\033[1;32m%-100.100s\n\033[0m' '${NAME} compile success!'

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