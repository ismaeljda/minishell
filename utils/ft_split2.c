#include "../minishell.h"

typedef struct s_split {
    int count;
    int i;
    int start;
    char in_simple_quote;
    char in_double_quote;
} t_split;

static t_split *init_struct(void)
{
    t_split *split;
    split = malloc (sizeof(t_split));
    if (!split)
        return (NULL);
    split->count = 0;
    split->i = 0;
    split->in_double_quote = 0;
    split->in_simple_quote = 0;
    split->start = 0;
    return (split);
}

char *ft_strndup(const char *s, size_t n)
{
    char *dup;
    size_t i;

    dup = (char *)malloc(n + 1);
    if (!dup)
        return NULL;
    i = 0;
    while (i < n && s[i] != '\0')
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return dup;
}

int count_tokens(char *str, char sep)
{
    t_split *s;

    s = init_struct();
    
    while (str[s->i]) {
        if (str[s->i] == '\'' && !s->in_double_quote)
            s->in_simple_quote = !s->in_simple_quote;
        else if (str[s->i] == '"' && !s->in_simple_quote)
            s->in_double_quote = !s->in_double_quote;
        
        if (str[s->i] == sep && !s->in_simple_quote && !s->in_double_quote)
            s->count++;
        
        s->i++;
    }
    return s->count + 1;
}

void handle_quotes(t_split *s, char *str)
{
    if (str[s->i] == '\'' && !s->in_double_quote)
        s->in_simple_quote = !s->in_simple_quote;
    else if (str[s->i] == '"' && !s->in_simple_quote)
        s->in_double_quote = !s->in_double_quote;
}

char **ft_split_quote(char *str, char sep) 
{
    t_split *s;
    char **result;

    if (!str)
        return (NULL);
    s = init_struct();
    s->count = count_tokens(str, sep);
    result = malloc(sizeof(char *) * (s->count + 1));
    s->count = 0;
    while (str[s->i]) 
    {
        handle_quotes(s, str);
        if (str[s->i] == sep && !s->in_simple_quote && !s->in_double_quote) 
        {
            result[s->count] = ft_strndup(str + s->start, s->i - s->start);
            s->start = s->i + 1;
            s->count++;
        }
        s->i++;
    }
    result[s->count] = ft_strndup(str + s->start, s->i - s->start);
    result[s->count + 1] = NULL;
    free(s);
    return result;
}
