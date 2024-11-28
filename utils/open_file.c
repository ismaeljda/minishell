#include "../minishell.h"

void handle_here_doc(char *limiter, t_type *head)
{
    int pipefd[2];
    char *line;

    if (pipe(pipefd) == -1)
    {
        perror("Pipe creation failed");
        exit(1);
    }
    while (1)
    {
        ft_printf_fd(1, " > ");
        line = get_next_line(0);
        if (!line)
            break;
        if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0 && 
            (line[ft_strlen(limiter)] == '\n' || line[ft_strlen(limiter)] == '\0'))
        {
            free(line);
            break;
        }
        write(pipefd[1], line, ft_strlen(line));
        free(line);
    }
    close(pipefd[1]);
    if (head->infile_fd != -1)
        close(head->infile_fd);
    head->infile_fd = pipefd[0];
}

void ft_infile(t_type *head)
{
    int infile = -1;
    int i = 0;

    while (head->redirection_in[i])
    {
        infile = open(head->redirection_in[i], O_RDONLY);
        if (infile == -1)
        {
            perror("infile");
            i++;
            continue;
        }
        if (head->infile_fd != -1)
            close(head->infile_fd);
        
        head->infile_fd = infile;
        i++;
    }
}

void ft_outfile(t_type *head)
{
    int outfile;
    int i;

    i = 0;
    while (head->redirection_out[i])
    {
        outfile = open(head->redirection_out[i], O_CREAT | O_WRONLY | O_TRUNC, 0777);
        if (outfile == -1)
            perror("outfile");
        i++;
        close (outfile);
    }
    if (head->last_out == 1)
        head->outfile = head->redirection_out[i - 1];
}

void ft_outfile_2(t_type *head)
{
    int outfile;
    int i;

    i = 0;
    while (head->outfile_append[i])
    {
        outfile = open(head->outfile_append[i], O_CREAT | O_WRONLY | O_APPEND, 0777);
        if (outfile == -1)
            perror("outfile");
        i++;
        close (outfile);
    }
    if (head->last_out == 2)
        head->outfile = head->outfile_append[i - 1];
}
