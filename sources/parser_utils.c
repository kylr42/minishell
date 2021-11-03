#include "../minishell.h"

int ft_skip_gap(const char *str)
{
    int i;
    char c;

    i = 0;
    c = *str;
    while (str[++i])
        if (str[i] == c)
            return (i);
    return (ft_raise_error(ERR_NEWL, 258));
}
