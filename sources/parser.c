#include "minishell.h"

static void ft_parser_pipes(char *str)
{
    bool b_pipe;
    bool b_words;

    b_pipe = false;
    while (*str && g_status == 0)
    {
        if (*str == '|' && !b_words)
            ft_raise_error_n(ERR_PIPE, 258);
        if (*str == '|')
        {
            b_pipe = true;
            b_words = false;
        }
        else if (!ft_strchr(" \t\v", *str))
            b_words = true;
        if (ft_strchr("'\"", *str))
            str += ft_skip_gap(str);
        str++;
    }
    if ((b_pipe && !b_words) && g_status == 0)
        ft_raise_error_n(ERR_NEWL, 258);
}

static char	*ft_parser_dollar(t_shell *shell, const char *s, size_t *i)
{
    char	*key;
    char	*value;

    (*i)++;
    if (s[*i] == '?')
    {
        (*i)++;
        return (ft_itoa(shell->cmd_status));
    }
    if (ft_strchr(" <>|$'\"\n=", s[(*i)]))
        return (ft_strdup("$"));
    key = ft_get_key(ft_isdigit(s[*i]), (char *) s, i);
    value = ft_get_el_env(shell, key);
    free(key);
    return (value);
}

static char	*ft_parser_gap(t_shell *shell, const char *s, size_t *i)
{
    t_list	*chars;
    char	quote;
    char	*quote_str;

    chars = NULL;
    quote = s[(*i)++];
    while (s[*i] && s[*i] != quote)
    {
        if (s[*i] == '$' && quote == '\"')
            ft_lstadd_back(&chars, ft_lstnew(ft_parser_dollar(shell, s, i)));
        else
            ft_lstadd_back(&chars, ft_lstnew(ft_substr(s, (*i)++, 1)));
    }
    if (s[*i])
        (*i)++;
    quote_str = ft_lst_to_str(chars);
    ft_lstclear(&chars, free);
    return (quote_str);
}

static void	ft_parser_word(t_shell *shell, const char *str, size_t *i)
{
    t_list	*chars;
    bool	is_redirect;

    chars = NULL;
    is_redirect = false;
    if (str[*i] == '<' || str[*i] == '>')
    {
        is_redirect = true;
        ft_lstadd_back(&chars, ft_lstnew(ft_substr(str, (*i)++, 1)));
        if (str[*i - 1] == str[*i])
            ft_lstadd_back(&chars, ft_lstnew(ft_substr(str, (*i)++, 1)));
        while (ft_strchr(" \t\v", str[*i]))
            (*i)++;
    }
    while (str[*i] && !ft_strchr(" <>|\n", str[*i]))
    {
        if (str[*i] == '$')
            ft_envadd_back(&chars, ft_parser_dollar(shell, str, i));
        else if (ft_strchr("'\"", str[*i]))
            ft_lstadd_back(&chars, ft_lstnew(ft_parser_gap(shell, str, i)));
        else
            ft_lstadd_back(&chars, ft_lstnew(ft_substr(str, (*i)++, 1)));
    }
    ft_add_keyword(shell, &chars, is_redirect);
}

static void    ft_parser_words(t_shell *shell, const char *str)
{
    size_t i;

    i = 0;
    shell->cmd = ft_allocate_cmd();
    while (str[i] && !g_status)
    {
        if (str[i] == '|')
        {
            ft_cmd_add_back(&shell->cmds, shell->cmd);
            shell->cmd = ft_allocate_cmd();
            i++;
        }
        else if (!ft_strchr(" \t\v", str[i]) && str[i] != '|')
            ft_parser_word(shell, str, &i);
        else
            i++;
    }
    ft_cmd_add_back(&shell->cmds, shell->cmd);
}

int ft_parser(t_shell *shell, char *str)
{
    char	*keyval;

    ft_parser_pipes(str);
    if (g_status != 0)
        return (1);
    ft_parser_words(shell, str);
    if (!g_status && shell->cmd && shell->cmd->lst)
    {
        keyval = ft_strjoin("_=", shell->cmd->lst->content);
        ft_update_el_env(shell, keyval);
        free(keyval);
    }
    return (g_status);
}
