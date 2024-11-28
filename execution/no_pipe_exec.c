#include "../minishell.h"

void ft_change_outfile(t_type *head)
{
    int outfile;

    outfile = 0;
    ft_outfile(head);
    ft_outfile_2(head);
    if (head->last_out == 1)
        outfile = open(head->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0777);
    else if (head->last_out == 2)
        outfile = open(head->outfile, O_CREAT | O_WRONLY | O_APPEND, 0777);
    if (dup2(outfile, STDOUT_FILENO) == -1) 
    {
        perror("dup2 output");
        close(outfile);
        exit(1);
    }
    close(outfile);
}

void ft_change_infile(t_type *head)
{
    if (dup2(head->infile_fd, STDIN_FILENO) == -1)
    {
        perror("dup2 input");
        close(head->infile_fd);
        exit(1);
    }
    close(head->infile_fd);
    head->infile_fd = -1;
}
