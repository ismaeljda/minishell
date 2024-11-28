#include "../minishell.h"

static int is_in_quotes(const char *str, int pos)
{
    int single_quote = 0;
    int double_quote = 0;
    int i = 0;
    
    while (i < pos)
    {
        if (str[i] == '\'' && !double_quote)
            single_quote = !single_quote;
        else if (str[i] == '\"' && !single_quote)
            double_quote = !double_quote;
        i++;
    }
    return (single_quote || double_quote);
}

char **ft_parse_input_redirections(char *str)
{
    int i = 0;
	int count = 0;
	int j;
	int k = 0;
    char **tab;

    while (str[i])
    {
        if (str[i] == '<' && !is_in_quotes(str, i))
        {
            if (str[i + 1] == '<')
                i += 2;
            else
                count++;
        }
        i++;
    }

    tab = malloc((count + 1) * sizeof(char *));
    if (!tab)
        return (NULL);

    i = 0;
    while (str[i])
    {
        if (str[i] == '<' && !is_in_quotes(str, i))
        {
            if (str[i + 1] == '<')
                i += 2;
            else
            {
                i++;
                while (str[i] == ' ')
                    i++;
                j = i;
                while (str[i] && str[i] != ' ' && str[i] != '<' && str[i] != '>')
                    i++;
                tab[k++] = ft_strndup(str + j, i - j);
            }
        }
        i++;
    }
    tab[k] = NULL;
    return (tab);
}

char **ft_parse_output_redirections(char *str)
{
    int i = 0;
	int count = 0;
	int j;
	int k = 0;
    char **tab;

    while (str[i])
    {
        if (str[i] == '>' && !is_in_quotes(str, i))
        {
            if (str[i + 1] == '>')
                i += 2;
            else
                count++;
        }
        i++;
    }

    tab = malloc((count + 1) * sizeof(char *));
    if (!tab)
        return (NULL);

    i = 0;
    while (str[i])
    {
        if (str[i] == '>' && !is_in_quotes(str, i))
        {
            if (str[i + 1] == '>')
                i += 2;
            else
            {
                i++;
                while (str[i] == ' ')
                    i++;
                j = i;
                while (str[i] && str[i] != ' ' && str[i] != '<' && str[i] != '>')
                    i++;
                tab[k++] = ft_strndup(str + j, i - j);
            }
        }
        i++;
    }
    tab[k] = NULL;
    return (tab);
}

char **ft_parse_here_doc(char *str)
{
    int i = 0;
	int count = 0;
	int j;
	int k = 0;
    char **tab;

    while (str[i])
    {
        if (str[i] == '<' && str[i + 1] == '<' && !is_in_quotes(str, i))
        {
            count++;
            i++;
        }
        i++;
    }

    tab = malloc((count + 1) * sizeof(char *));
    if (!tab)
        return (NULL);

    i = 0;
    while (str[i])
    {
        if (str[i] == '<' && str[i + 1] == '<' && !is_in_quotes(str, i))
        {
            i += 2;
            while (str[i] == ' ')
                i++;
            j = i;
            while (str[i] && str[i] != ' ' && str[i] != '<' && str[i] != '>')
                i++;
            tab[k++] = ft_strndup(str + j, i - j);
        }
        else
            i++;
    }
    tab[k] = NULL;
    return (tab);
}

char **ft_parse_outfile_append(char *str)
{
    int i = 0;
	int count = 0;
	int j;
	int k = 0;
    char **tab;

    while (str[i])
    {
        if (str[i] == '>' && str[i + 1] == '>' && !is_in_quotes(str, i))
        {
            count++;
            i++;
        }
        i++;
    }
    tab = malloc((count + 1) * sizeof(char *));
    if (!tab)
        return (NULL);

    i = 0;
    while (str[i])
    {
        if (str[i] == '>' && str[i + 1] == '>' && !is_in_quotes(str, i))
        {
            i += 2;
            while (str[i] == ' ')
                i++;
            j = i;
            while (str[i] && str[i] != ' ' && str[i] != '>' && str[i] != '<')
                i++;
            tab[k++] = ft_strndup(str + j, i - j);
        }
        else
            i++;
    }
    tab[k] = NULL;
    return (tab);
}

char *ft_command(char *str)
{
    int i;
    char *commande = "";
    char *tmp;
    int j = 0;

    t_quote_state *state;
    state = malloc(sizeof(t_quote_state));
    state->double_quote = 0;
    state->single_quote = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == '<')
        {
            if (str[i + 1] == '<')
                i +=2;
            else 
                i++;
            while (str[i] == ' ' && str[i])
                    i++;
            while (str[i] && str[i] != ' ' && str[i] != '<' && str[i] != '>')
                    i++;
        }
        else if (str[i] == '>')
        {
            if (str[i + 1] == '>')
                i +=2;
            else 
                i++;
            while (str[i] == ' ' && str[i])
                    i++;
            while (str[i] && str[i] != ' ' && str[i] != '<' && str[i] != '>')
                    i++;
        }
        else if (str[i] && str[i] == ' ')
            i++;
        else 
        {
            j = i;
            while (str[i] && str[i] != '<' && str[i] != '>')
                i++;
            tmp = ft_process_quote(str + j, i - j, state);
            if (state->single_quote != 2 )
			    tmp = ft_expander(tmp);
            tmp = ft_strjoin(tmp, " ");
            commande = ft_strjoin(commande, tmp);
            free (tmp);
        }
    }
    return (commande);
}
