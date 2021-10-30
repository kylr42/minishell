#include "minishell.h"

int main(int argc, char *argv[], char *envp[])
{
    t_shell shell;

    if (argc > 1)
        printf(MAG"Hello, %s! %s starts...\n"RESET, getenv("USER"), argv[0]);

    ft_init(&shell, envp);
    ft_loop(&shell);
	return (0);
}
