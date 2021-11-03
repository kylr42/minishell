#include "../minishell.h"

static int ft_parse_pipes(char *str)
{
    int count;
    bool b_pipe;
    bool b_words;

    count = 0;
    b_pipe = false;
    while (*str)
    {
        if (*str == '|' && !b_words)
            return ft_raise_error(ERR_PIPE, 258);
        if (*str == '|')
        {
            b_pipe = true;
            b_words = false;
            count++;
        }
        else if (!ft_strchr(" \t\v", *str))
            b_words = true;
        if (ft_strchr("'\"", *str))
        {
            if (ft_skip_gap(str) == -1)
                break;
            str += ft_skip_gap(str);
        }
        str++;
    }
    if (b_pipe && !b_words)
        return ft_raise_error(ERR_NEWL, 258);
    return (count);
}
//
//void    parsing_by_words(t_shell *shell, char *str)
//{
//
//}

int ft_parser(t_shell *shell, char *str)
{
    shell->count_pipes = ft_parse_pipes(str);
    if (shell->count_pipes == -1)
        return (1);
//    parsing_by_words(shell, str);
    return (0);
}
