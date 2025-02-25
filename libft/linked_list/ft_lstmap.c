/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:07:27 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/17 18:44:50 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	free_for_norm(void *content, t_list *head, void (*del)(void *))
{
	del(content);
	ft_lstclear(&head, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*head;
	t_list		*new_elem;
	void		*new_content;

	if (!lst || !f)
		return (NULL);
	head = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new_elem = ft_lstnew(new_content);
		if (!new_elem)
		{
			free_for_norm(new_content, head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_elem);
		lst = lst->next;
	}
	return (head);
}
