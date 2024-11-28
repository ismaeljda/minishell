/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus->c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:31:18 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 14:07:01 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	if (lst == NULL)
		return (NULL);
	current = lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list *node1;
	t_list *node2;
	t_list *node3;
	t_list *node4;
	t_list *last;
	char *content;
	node1 = ft_lstnew("el1");
	node2 = ft_lstnew("el2");
	node3 = ft_lstnew("el3");
	node4 = ft_lstnew("el4");

	ft_lstadd_front(&node2, node1);
	ft_lstadd_front(&node2, node3);
	ft_lstadd_front(&node2, node4);
	last = ft_lstlast(node2);
	content = (char *)last->content;
	printf("%s\n", content);
	return (0);
}*/