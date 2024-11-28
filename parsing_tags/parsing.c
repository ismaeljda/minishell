#include "../minishell.h"

static void	free_str_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_list(t_type *head)
{
	t_type	*current;
	t_type	*next;

	current = head;
	while (current)
	{
		if (current->cmd && current->cmd[0] != '\0')
			free(current->cmd);
		if (current->redirection_in)
			free_str_array(current->redirection_in);
		if (current->here_doc)
			free_str_array(current->here_doc);
		if (current->redirection_out)
			free_str_array(current->redirection_out);
		if (current->outfile_append)
			free_str_array(current->outfile_append);
		if (current->infile)
			free(current->infile);
		if (current->outfile)
			free(current->outfile);
		if (current->infile_fd != -1)
			close(current->infile_fd); // check si deja close 
		next = current->next;
		free(current);
		current = next;
	}
}

t_type	*init_node(char *str)
{
	t_type	*node;

	node = malloc(sizeof(t_type));
	if (!node)
		return (NULL);
	node->cmd = ft_command(str);
	node->redirection_in = ft_parse_input_redirections(str);
	node->here_doc = ft_parse_here_doc(str);
	node->last_in = determine_last_in_type(str);
	node->redirection_out = ft_parse_output_redirections(str);
	node->outfile_append = ft_parse_outfile_append(str);
	node->last_out = determine_last_out_type(str);
	node->indirection = determine_redirection_type(str);
    node->outdirection = determine_redirection_type_2(str);
    node->infile_fd = -1;
    node->infile = NULL;
	node->outfile = NULL;
	node->next = NULL;
    free (str);
	return (node);
}

void ft_in(t_type *head)
{
 if (head->indirection == 2 || head->indirection == 3)
    {
        int i = 0;
        while (head->here_doc[i])
        {
            handle_here_doc(head->here_doc[i], head);
            i++;
        }
    }
    if (head->indirection == 1 || head->indirection == 3)
        ft_infile(head);
}

void check_quote (char *str, t_quote *quote)
{
    int k;
    
    k = 0;
    while (str[k])
    {
        if (str[k] == '"')
            quote->count_double++;
        if (str[k] == '\'')
            quote->count_single++;
        k++;
    }
}

char *ft_check_last(char *str, int i)
{
    char *line;
    t_quote *quote;

    quote = malloc(sizeof(t_quote));
    if (!quote)
        return (NULL);
    quote->count_single = 0;
    quote->count_double = 0;

    check_quote(str, quote);
    i = ft_strlen(str) - 1;
    if (str[i] == '|' || quote->count_double % 2 != 0 || quote->count_single % 2  != 0)
    {
        while (1)
        {
            line = readline("> ");
            line = ft_strtrim(line, " ");
            check_quote(line, quote);
            i = ft_strlen(line) - 1;
            if (line[i] != '|' && quote->count_single % 2 == 0 && quote->count_double % 2 == 0)
                break;
        }
        return (ft_strjoin(str, line));
    }
    return (str);
}

int ft_check_forbidden(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == ';' || str[i] == '\\')
        {
            ft_printf_fd(2, "Error: forbidden character '%c' detected\n", str[i]);
            return (1);
        }
        i++;
    }
    return (0);
}

t_type *init_list(char *input, t_pipex *info) 
{
    t_type *node;
    t_type *head;
    char **tab;
    int i;

    info->ac = 4;
    input = ft_strtrim(input, " ");
    input = ft_check_last(input, 0);
    tab = ft_split_quote(input, '|');
    i = 0;
    head = NULL;
    while (tab[i])
    {
        // tab[i] = ft_process_quote(tab[i], info->env);
        tab[i] = ft_strtrim(tab[i], " ");
        node = init_node(tab[i]);
        ft_in(node);
        if (head == NULL)
            head = node;
        else
            ft_lstadd_back2(&head, node);
        i++;
    }
    return (head);
}
