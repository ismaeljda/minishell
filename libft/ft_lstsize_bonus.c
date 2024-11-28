/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus->c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:32:20 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 12:32:25 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
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
/*
#include <stdio.h>

int	main(void)
{
	t_list *node1;
	t_list *node2;
	t_list *node3;
	t_list *node4;
	t_list *current;
	node1 = ft_lstnew("el1");
	node2 = ft_lstnew("el2");
	node3 = ft_lstnew("el3");
	node4 = ft_lstnew("el4");

	ft_lstadd_front(&node2, node1);
	ft_lstadd_front(&node2, node3);
	ft_lstadd_front(&node2, node4);
	printf("%d\n", ft_lstsize(node4));
	current = node4;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}*/