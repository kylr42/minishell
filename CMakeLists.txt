cmake_minimum_required(VERSION 3.19.2)
project(minishell C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-lreadline")
include_directories("includes")

link_directories("~/.brew/opt/readline/lib")

FILE(GLOB LIBFT libft/*.c)
FILE(GLOB SOURCE sources/*.c)
FILE(GLOB BUILTINS sources/builtins/*.c)


add_executable(minishell includes/minishell.h ${LIBFT} ${SOURCE} ${BUILTINS} main.c includes/builtins.h includes/includes.h includes/parser.h includes/logic.h sources/builtins/unset.c sources/builtins/cd.c sources/builtins/cd_utils.c sources/builtins/export.c sources/builtins/export_print.c sources/builtins/export_utils.c libft/ft_split_free.c sources/builtins/help.c)
