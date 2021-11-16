#include "minishell.h"

int main(int argc, char *argv[], char *envp[])
{
    t_shell shell;
    int     rl_catch_signals;

    if (argc > 1)
        printf(MAG"Hello, %s! %s loading...\n"RESET, getenv("USER"), argv[0]);
    rl_catch_signals = 0;
    rl_set_signals();
    ft_init(&shell, envp);
    ft_signal_main();
    ft_loop(&shell);
    return (0);
}
