#include "../minishell.h"

void ft_first(t_type *current, t_type *first, int prev_fd)
{
    if (current != first && prev_fd != -1)
    {
        dup2(prev_fd, 0);
        close(prev_fd);
    }
}

void ft_last(t_type *current, t_type *last, int pipe_out, int pipe_in)
{
    if (current != last)
    {
        dup2(pipe_out, 1);
        close(pipe_out);
        close(pipe_in);
    }
}
void ft_pipe_launch(t_type *current, t_type *last, int pipe_fd[2])
{
    if (current != last)
    {
        if (pipe(pipe_fd) == -1)
        {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }
}
