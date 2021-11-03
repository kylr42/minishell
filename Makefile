CC=gcc
CFLAGS=-lreadline -L ~/.brew/opt/readline/lib

NAME = minishell

INC = .
SRCS_DIR = ./sources/
OBJS_DIR = ./objects/

LIB_DIR = ./libft/
LIBFT = ${LIB_DIR}libft.a

SRCS_FILES = ft_lst.c echo.c init.c loop.c parser.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))


all: ${NAME}

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

${LIBFT}:
	@make -C $(LIB_DIR)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -I$(LIB_DIR) -I$(INC) -c $< -o $@
	@printf "\033[0;33mObject %-40.100s [\033[0;32m✔\033[0;33m]\r" $@

${NAME}: $(OBJS_DIR) $(OBJS) $(LIBFT)
	@$(CC) ${CFLAGS} ${LIBFT} ${OBJS} -I$(LIB_DIR) main.c -o ${NAME}
	@printf '\033[1;32m%-40.40s\n\033[0m' '${NAME} compile success!'

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