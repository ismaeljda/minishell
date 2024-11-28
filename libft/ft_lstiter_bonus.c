/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus->c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:30:49 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 12:30:56 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (!lst)
		return ;
	current = lst;
	while (current)
	{
		f(current->content);
		current = current->next;
	}
}

/*#include <stdio.h>

void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list *list = ft_lstnew(ft_strdup("Premier"));
	list->next = ft_lstnew(ft_strdup("Deuxième"));
	list->next->next = ft_lstnew(ft_strdup("Troisième"));
	printf("Contenu de la liste :\n");
	ft_lstiter(list, print_content);
	return (0);
}*/