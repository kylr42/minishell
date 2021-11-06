cmake_minimum_required(VERSION 3.20)
project(minishell C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-lreadline -L ~/.brew/opt/readline/lib")

FILE(GLOB LIBFT libft/*.c)
FILE(GLOB SOURCE sources/*.c)


add_executable(minishell minishell.h ${LIBFT} ${SOURCE} main.c sources/errors.c sources/parser_utils.c sources/utils.c sources/env_utils.c)
