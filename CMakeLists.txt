cmake_minimum_required(VERSION 3.20)
project(minishell C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-lreadline -L ~/.brew/opt/readline/lib")

FILE(GLOB LIBFT libft/*.c)
add_executable(minishell minishell.h ${LIBFT}
        sources/echo.c main.c sources/loop.c sources/init.c sources/ft_lst.c)
