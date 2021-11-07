#include "../minishell.h"

void	ft_envadd_back(t_list	**chars, char *env_val)
{
    if (*env_val)
        ft_lstadd_back(chars, ft_lstnew(env_val));
    else
        free(env_val);
}

char	*ft_get_key(bool digit, char *s, size_t *i)
{
    char	*key;
    t_list	*key_chars;

    key_chars = NULL;
    while (s[*i] && ft_isalnum(s[*i]) && !(ft_isalpha(s[*i]) && digit))
        ft_lstadd_back(&key_chars, ft_lstnew(ft_substr(s, (*i)++, 1)));
    key = ft_lst_to_str(key_chars);
    ft_lstclear(&key_chars, free);
    return (key);
}

int     ft_skip_gap(const char *str)
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

void	ft_add_keyword(t_shell *shell, t_list **chars, bool is_redirect)
{
    char	*keyword;
    char	*msg;

    keyword = ft_lst_to_str(*chars);
    ft_lstclear(chars, free);
    if (is_redirect)
    {
        if (ft_strlen(keyword) == 1
        || (ft_strlen(keyword) == 2 && keyword[0] == keyword[1]))
        {
            msg = ft_strjoin("shell: syntax error near unexpected token ", keyword);
            ft_raise_error(msg, 0);
            g_status = 258;
            free(msg);
        }
        ft_lstadd_back(&shell->cmd->redirects, ft_lstnew(keyword));
    }
    else
        ft_lstadd_front(&shell->cmd->lst, ft_lstnew(keyword));
}

