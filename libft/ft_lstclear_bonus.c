/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus->c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:29:50 by isall             #+#    #+#             */
/*   Updated: 2024/10/14 12:30:12 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	if (!lst)
		return ;
	while (current)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

/*#include <stdio.h>
void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *list = ft_lstnew(ft_strdup("Premier"));
	list->next = ft_lstnew(ft_strdup("Deuxième"));
	list->next->next = ft_lstnew(ft_strdup("Troisième"));
	list->next->next->next = ft_lstnew(ft_strdup("Quatrième"));
	list->next->next->next->next = ft_lstnew(ft_strdup("Cinquième"));

	// Pour afficher avant supression
	printf("Contenu avant suppression:\n");
	t_list *tmp = list;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	// Pour supprimer à partir du 3ème élément
	t_list *to_delete = list->next->next;
	list->next->next = NULL;
	ft_lstclear(&to_delete, del_content);

	// Affichage après la suppression partielle
	printf("\nContenu après suppression partielle:\n");
	tmp = list;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&list, del_content);

	return (0);
}*/