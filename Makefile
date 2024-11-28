# Variables
NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR) -I.
PRE_EXEC = ./execution/
PRE_PARSING = ./parsing_tags/
PRE_UTILS = ./utils/
PRE_SRCS = ./
#PRE_BUILTIN = ./builtin/

# Sources
SRC_EXEC = execution.c no_pipe_exec.c path_execve_cmd.c pipe_exec.c
SRC_PARSING = parsing.c tag.c tag_utils.c expander.c quote.c
SRC_UTILS = lst_utils.c open_file.c ft_split2.c utils.c
SRC_MAIN = main.c
#SRC_BUILTIN = builtin.c env_exc.c exit_exc.c

SRCS = $(addprefix $(PRE_EXEC), $(SRC_EXEC)) \
       $(addprefix $(PRE_PARSING), $(SRC_PARSING)) \
       $(addprefix $(PRE_UTILS), $(SRC_UTILS)) \
       $(addprefix $(PRE_SRCS), $(SRC_MAIN)) \
#	   $(addprefix $(PRE_BUILTIN), $(SRC_BUILTIN))

OBJS = $(SRCS:.c=.o)

# Règles
all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT) -lreadline

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re