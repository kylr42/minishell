CC=gcc
CFLAGS= -Wall -Wextra -Werror
RFLAGS= -lreadline -L ~/.brew/opt/readline/lib

NAME = minishell

INC = includes
SRCS_DIR = ./sources/
OBJS_DIR = ./objects/
READ_INC = ~/.brew/opt/readline/include/readline/

LIB_DIR = ./libft/
LIBFT = ${LIB_DIR}libft.a

SRCS_FILES = builtins/env.c builtins/exit.c builtins/echo.c builtins/pwd.c builtins/cd.c builtins/cd_utils.c \
			builtins/unset.c builtins/export.c builtins/export_print.c builtins/export_utils.c \
			dups.c env_utils.c init.c errors.c loop.c redirects.c  \
			lst.c parser.c parser_utils.c pipes_utils.c pipes.c utils.c signals.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))


all: ${NAME}

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)builtins $(OBJS_DIR)

${LIBFT}:
	@make -C $(LIB_DIR)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -I$(LIB_DIR) -I$(INC) -I$(READ_INC) -c $< -o $@
	@printf "\033[0;33mObject %-40.100s [\033[0;32m✔\033[0;33m]\r" $@

${NAME}: $(LIBFT) $(OBJS_DIR) $(OBJS) $(SRCS) main.c
	@$(CC) ${CFLAGS} ${LIBFT} -I$(INC) -I$(LIB_DIR) -I$(READ_INC) $(RFLAGS) ${OBJS} main.c -o ${NAME}
	@printf '\033[1;32m%-100.100s\n\033[0m' '${NAME} compile success!'

clean:
	@rm -rf $(OBJS_DIR)
	@make clean -C $(LIB_DIR)
	@printf '\033[1;35mDelete objects success!\n\033[0m'

fclean: clean
	@make fclean -C $(LIB_DIR)
	@rm -rf ${NAME}
	@printf '\033[1;35mDelete ${NAME} success!\n\033[0m'

re: fclean all

.PHONY:	all clean fclean re