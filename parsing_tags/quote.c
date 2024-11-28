#include "../minishell.h"

void quote_state(char *str, int len, t_quote_state* state)
{
    int k = 0;
    int i = 0;

    while (k < len)
    {
        if(str[i] == '\'' && state->double_quote != 1 && state->single_quote != 1)
            state->single_quote = 1;
        else if (str[i] == '\'' && state->double_quote != 1 && state->single_quote == 1)
            state->single_quote = 2;
        if(str[i] == '"' && state->single_quote != 1 && state->double_quote != 1)
            state->double_quote = 1;
        else if (str[i] == '"' && state->single_quote != 1 && state->double_quote == 1)
            state->double_quote = 2;
        k++;
        i++;
    }
}

char *ft_process_quote(char *str, int len, t_quote_state *state)
{
    char *result;
    int i = 0;
    int j = 0;
    quote_state(str, len, state);
    if (state->double_quote == 2)
    {
        result = malloc(len - 1);
        if (!result)
            return (NULL);
        while (i < len)
        {
            if (str[i] != '"')
            {
                result[j] = str[i];
                j++;
            }
            i++;
        }
        result[j] ='\0';
    }
    else if (state->single_quote == 2)
    {
        result = malloc(len - 1);
        if (!result)
            return (NULL);
        while (i < len)
        {
            if (str[i] != '\'')
            {
                result[j] = str[i];
                j++;
            }
            i++;
        }
        result[j] ='\0';
    }
    else 
        return (str);
    return (result);
}