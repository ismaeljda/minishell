/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus->c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:43:52 by isall             #+#    #+#             */
/*   Updated: 2024/11/19 19:26:41 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_db(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**get_path_2(char **env)
{
	char	*path;
	char	**path_2;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
		{
			path = env[i];
			path_2 = ft_split(path + 5, ':');
			if (!path_2)
			{
				perror("split failed");
				exit(1);
			}
		}
		i++;
	}
	return (path_2);
}

char	*get_path(char **env, char *cmd)
{
	int		i;
	char	**path_2;
	char	*path;

	path_2 = get_path_2(env);
	i = 0;
	while (path_2[i])
	{
		path = ft_strjoin(path_2[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, X_OK) == 0)
		{
			free_db(path_2);
			return (path);
		}
		i++;
	}
	free_db(path_2);
	return (NULL);
}

int ft_search_ls(t_type *head)
{
	t_type *current;

	current = head;
	while (current)
	{
		if (ft_strncmp(current->cmd, "ls", 2) == 0 || ft_strncmp(current->cmd, "/usr/bin/ls", 12) == 0 || ft_strncmp(current->cmd, "/bin/ls", 12) == 0)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ft_execute(char **env, char *path, t_type *head)
{
	char	**split;
	char *line;

	path = ft_strtrim(path, " ");
	split = ft_split(path, ' ');
	if (!split)
	{
		perror("split failed");
		exit(1);
	}
	if (access(split[0], X_OK) != 0)
	{
		path = get_path(env, split[0]);
		if (!path)
		{
			fprintf(stderr, "Command not found: %s\n", split[1]);
			free_db(split);
			exit(1);
		}
	}
	else
		path = ft_strdup(split[0]);
	if (ft_strncmp(path, "/bin/cat", 9) == 0 && !split[1] && ft_search_ls(head) == 1)
	{
		while (1)
		{
			line = get_next_line(0);
			ft_printf_fd(1, line);
			if (line)
				break;
		}
	}
	else
		execve(path, split, env);
	free_db(split);
	free(path);
}
