#include "minishell.h"

pid_t g_current_pid = 0;
int g_exit_status = 0;

t_pipex	*init_info(int ac, char **av, char **env)
{
	t_pipex	*info;

	info = malloc(sizeof(t_pipex));
	if (!info)
		exit(1);
	info->av = av;
	info->env = env;
	info->ac = ac;
	return (info);
}

int	ft_nbr_here_doc(t_type *head)
{
	t_type	*current;
	int		count;

	current = head;
	count = 0;
	while (current)
	{
		if (current->indirection == 2 || current->indirection == 3)
			count++;
		current = current->next;
	}
	return (count);
}

void reset_terminal_line(void)
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ECHOCTL;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void signal_handler(int signum)
{
    if (signum == SIGINT)
    {
        if (g_current_pid > 0)
            kill(g_current_pid, SIGINT);
        else
        {
            write(STDOUT_FILENO, "\n", 1);
            reset_terminal_line();
            write(STDOUT_FILENO, "$minishell $ ", 13);
        }
    }
    else if (signum == SIGQUIT)
    {
        if (g_current_pid > 0)
            kill(g_current_pid, SIGQUIT);
        else
            write(STDOUT_FILENO, "\b\b  \b\b", 6);
    }
}


int	main(int ac, char **av, char **env)
{
	char	*input;
	t_type	*head;
	t_pipex	*info;

	info = init_info(ac, av, env);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	while (1)
	{
		g_current_pid = 0;
		input = readline("$minishell $");
		if (input == NULL)
		{
			printf("\nExit\n");
			break ;
		}
		if (*input)
		{
            add_history(input);
            if (ft_check_forbidden(input) == 0)
            {
                head = init_list(input, info);
                free(input);
                if (ft_lstsize2(head) > 1)
                    ft_pipe(head, info);
                else
                    ft_no_pipe(head, info);
                ft_free_list(head);
            }
		}
	}
	free(info);
	return (0);
}
