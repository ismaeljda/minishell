#include "../minishell.h"

char* ft_strcat(char* dest, const char* src) 
{
    size_t dest_len = ft_strlen(dest);
    size_t i = 0;

    while (src[i]) 
    {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}


char* ft_strcpy(char* dest, const char* src) 
{
    size_t i = 0;
    while (src[i]) 
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}