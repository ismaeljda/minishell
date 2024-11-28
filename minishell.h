#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>
# include <termios.h>

extern int g_exit_status;
extern pid_t g_current_pid;

typedef struct s_type
{
	char			*cmd;
	char			**redirection_in;
	char			**redirection_out;
	char			**outfile_append;
	char			**here_doc;
	char			*infile;
	char			*outfile;
	int 			infile_fd;
	int				last_in;
	int				last_out;
	int				indirection;
	int				outdirection;
	struct s_type	*next;
}					t_type;
typedef struct s_pipex
{
	int				ac;
	char			**av;
	char			**env;
}					t_pipex;

typedef struct s_quote_state
{
    int single_quote;
    int double_quote;
} t_quote_state;

// typedef struct s_quote_state
// {
// 	int				in_single_quote;
// 	int				in_double_quote;
// 	int				escaped;
// 	char			**env;
// 	int				j;
// }					t_quote_state;

typedef struct s_size_calc
{
	int				size;
	int				var_size;
	char			**env;
}					t_size_calc;

typedef struct s_process_data
{
	t_quote_state	state;
	char			**env;
	int				j;
}					t_process_data;

typedef struct s_quote{
    int count_single;
    int count_double;
} t_quote;
// parsing
t_type				*init_list(char *input, t_pipex *info);
void quote_state(char *str, int len, t_quote_state* state);
char *ft_process_quote(char *str, int len, t_quote_state *state);
char* get_env_var(char* var_name);
char* ft_expander(char* str);
// char				*ft_process_quote(char *str, char **env);
int					calculate_expanded_size(char *str, char **env);
t_quote_state		init_state(char **env);
int					is_var_char(char c);
int					get_var_length(const char *str);
char				*get_env_value(char **env, const char *var_name);
int					expand_exit_code(char *result, int *i, int *j);
int					expand_pid(char *result, int *i, int *j);
int					expand_variable(char *str, char *result, int *i,
						t_quote_state *state);
void				process_char2(char *str, t_quote_state *state, char *result,
						int *i);
int ft_check_forbidden(char *str);

// tag
int determine_redirection_type(char *str);
int	determine_redirection_type_2(char *str);
int determine_last_in_type(char *str);
int determine_last_out_type(char *str);
char    **ft_parse_input_redirections(char *str);
char    **ft_parse_output_redirections(char *str);
char    **ft_parse_here_doc(char *str);
char    **ft_parse_outfile_append(char *str);
char    *ft_command(char *str);

// functions utils
void				ft_lstadd_back2(t_type **lst, t_type *new);
int					ft_lstsize2(t_type *lst);
t_type				*ft_lstlast2(t_type *lst);
char				**ft_split_quote(char *str, char sep);
char				*ft_strndup(const char *s, size_t n);
char* ft_strcat(char* dest, const char* src);
char* ft_strcpy(char* dest, const char* src);

// execute
void	ft_execute(char **env, char *path, t_type *head);
void				ft_infile(t_type *head);
void 				ft_outfile(t_type *head);
void	handle_here_doc(char *limiter, t_type *head);
void	handle_here_doc_pipe(char *limiter, t_type *head, char *file);

// execute simple
void				ft_no_pipe(t_type *head, t_pipex *info);
void				ft_change_infile(t_type *head);
void				ft_change_outfile(t_type *head);
void 				ft_outfile_2(t_type *head);

// execute multiple
void				ft_pipe(t_type *first, t_pipex *info);
void				ft_first(t_type *current, t_type *first, int prev_fd);
void				ft_last(t_type *current, t_type *last, int pipe_out,
						int pipe_in);
void				ft_pipe_launch(t_type *current, t_type *last,
						int pipe_fd[2]);

// FREEZER
void				free_dp(char **tab);
void	ft_free_list(t_type *head);

#endif