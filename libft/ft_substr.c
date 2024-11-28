/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:39:15 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 15:54:23 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*ft_substr(char const *s, unsigned int start, size_t len)
  {
  size_t			i;
  size_t			j;
  char			*str;
  char			*new;
  size_t			slen;
  size_t			finish;
  unsigned int	slen;
  unsigned int	dlen;
  unsigned int	klen;
  char			*res;
  size_t			i;

  str = (char *)malloc(sizeof(*s) * (len + 1));
  if (!str)
  return (NULL);
  i = 0;
  j = 0;
  while (s[i])
  {
  if (i >= start && j < len)
  {
  str[j] = s[i];
  j++;
  }
  i++;
  }
  str[j] = '\0';
  return (str);
  }*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		res = ft_strdup("");
		return (res);
	}
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
char	*result;

result = ft_substr("", 1, 1);
printf("Sous-chaîne 1: %s\n", result);
free(result);
return (0);
}
*/
