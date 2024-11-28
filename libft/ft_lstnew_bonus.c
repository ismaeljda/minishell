/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus->c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:31:53 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 12:32:01 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list *node;
	char *content = "Hello, world!";
	node = ft_lstnew(content);
	if (node)
		printf("Node content: %s\n", (char *)node->content);
	free(node);
	return (0);
}*/