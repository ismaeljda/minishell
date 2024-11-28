#include "../minishell.h"

void ft_no_pipe(t_type *head, t_pipex *info)
{
    pid_t pid;
    int status;
    
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    if (pid == 0)
    {
        if (head->indirection > 0)
            ft_change_infile(head);
        if (head->outdirection > 0)
            ft_change_outfile(head);
        if (head->cmd[0] != '\0')
            ft_execute(info->env, head->cmd, head);
        // perror("execve");
        exit(1);
    }
    else
    {
        g_current_pid = pid;
        waitpid(pid, &status, 0);
        g_current_pid = 0;
    }
}


void ft_pipe(t_type *first, t_pipex *info)
{
    pid_t pid;
    t_type *current;
    t_type *last;
    int pipe_fd[2];
    int prev_fd;
    
    prev_fd = -1;
    current = first;
    last = ft_lstlast2(first);
    
    while (current)
    {
        ft_pipe_launch(current, last, pipe_fd);
        
        pid = fork();
        if (pid == 0)
        {
            ft_first(current, first, prev_fd);
            ft_last(current, last, pipe_fd[1], pipe_fd[0]);
            
            if (current->indirection > 0)
                ft_change_infile(current);
            if (current->outdirection > 0)
                ft_change_outfile(current);
            if (current->cmd[0] != '\0')
                ft_execute(info->env, current->cmd, first);
            exit(1);
        }
        g_current_pid = pid;
        if (current != last)
            close(pipe_fd[1]);
        prev_fd = pipe_fd[0];
        current = current->next;
    }
    while (wait(NULL) > 0);
    g_current_pid = 0;
}
