#include "../minishell.h"

# define ERR_PIPE	"shell: Syntax error near unexpected token '|'"
# define ERR_NEWL	"shell: Syntax error near newline"
# define ERR_TKN	"shell: syntax error near unexpected token: "


int ft_raise_error(char *error, int code)
{
    ft_putstr_fd(RED, 2);
    ft_putstr_fd(error, 2);
    ft_putendl_fd(RESET, 2);
    return (-1);
}


static int ft_skip_gap(const char *str)
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

int ft_parser(t_shell *shell, char *str)
{
    shell->count_pipes = ft_parse_pipes(str);
    return (0);
}