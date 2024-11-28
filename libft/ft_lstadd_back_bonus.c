/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus->c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:32:40 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 12:41:23 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

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
/*
#include <stdio.h>

int	main(void)
{
t_list	*head = NULL;
t_list	*node1 = ft_lstnew("Node 1");
t_list	*node2 = ft_lstnew("Node 2");
t_list	*node3 = ft_lstnew("Node 3");
t_list	*node4 = ft_lstnew("Node 4");
t_list	*current = head;

ft_lstadd_front(&head, node1);
ft_lstadd_front(&head, node2);
ft_lstadd_back(&head, node3);
ft_lstadd_back(&head, node4);
while (current)
{
printf("Content: %s\n", (char *)current->content);
current = current->next;
}
free(node1);
free(node2);
free(node3);
return (0);
}*/
