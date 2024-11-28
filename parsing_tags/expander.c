#include "../minishell.h"

char* get_env_var(char* var_name) 
{
    char *value;
    char *cleaned_var_name = var_name;

    if (cleaned_var_name[0] == '$')
        cleaned_var_name++;

    value = getenv(cleaned_var_name);

    if (value == NULL)
        return NULL;

    return ft_strdup(value);
}

char* ft_expander(char* str) 
{
    int i = 0;
    char* result = ft_strdup("");

    while (str[i]) 
    {
        if (str[i] == '$') 
        {
            int j = i + 1;
            while (str[j] && str[j] != ' ' && str[j] != '$' && str[j] != '\'')
                j++;

            char* var_name = ft_strndup(str + i + 1, j - i - 1);
            char* expanded_var = get_env_var(var_name);

            char* temp = result;
            size_t total_len = ft_strlen(temp);
            if (expanded_var)
                total_len += ft_strlen(expanded_var);
            result = malloc(total_len + 1);
            ft_strcpy(result, temp);
            if (expanded_var)
                ft_strcat(result, expanded_var);
            free(temp);
            free(var_name);
            if (expanded_var)
                free(expanded_var);
            i = j;
        } 
        else 
        {
            char* temp = result;
            char c[2] = {str[i], '\0'}; // do it in a correct way for the norm

            size_t total_len = ft_strlen(temp) + 1;
            result = malloc(total_len + 1);
            ft_strcpy(result, temp);
            ft_strcat(result, c);
            free(temp);
            i++;
        }
    }
    return (result);
}