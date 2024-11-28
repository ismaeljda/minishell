/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:48:34 by isall             #+#    #+#             */
/*   Updated: 2024/11/18 17:20:40 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_in(int fd, char *store)
{
	char	buffer[BUFFER_SIZE + 1];
	int		byte_read;
	char	*tmp;

	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(store);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		tmp = ft_strjoin(store, buffer);
		free(store);
		store = tmp;
		if (store && ft_my_strchr(store, '\n'))
			break ;
	}
	return (store);
}

static int	get_line_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i + 2);
	return (i + 1);
}

static char	*extract_line(char *str)
{
	int		i;
	char	*line;
	int		line_length;

	if (!str || !*str)
		return (NULL);
	line_length = get_line_length(str);
	line = (char *)malloc(line_length);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != 0)
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}

static char	*extract_static(char *str)
{
	char	*store;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	store = ft_strdup(str + i + 1);
	free(str);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (store)
		{
			free(store);
			store = NULL;
		}
		return (NULL);
	}
	store = fill_in(fd, store);
	if (!store)
		return (NULL);
	line = extract_line(store);
	if (!line)
	{
		free(store);
		store = NULL;
		return (NULL);
	}
	store = extract_static(store);
	return (line);
}
// #include <fcntl.h>
// #include <stdio.h>
// int main(void) {
// 	int i = 0;
// 	char *line;
// 	int fd = open("test.txt", O_RDONLY);

// 	while (i < 6) {
// 		line = get_next_line(fd);
// 		if (line) {
// 			printf("%s", line);
// 			free(line);
// 		}
// 		i++;
// 	}
// 	close(fd);
// }