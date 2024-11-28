#include "../minishell.h"

void	ft_lstadd_back2(t_type **lst, t_type *new)
{
	t_type	*current;

	current = *lst;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
}

int	ft_lstsize2(t_type *lst)
{
	t_type	*current;
	int		i;

	current = lst;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

t_type	*ft_lstlast2(t_type *lst)
{
	t_type	*current;

	if (lst == NULL)
		return (NULL);
	current = lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}
