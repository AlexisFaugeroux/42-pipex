/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:40:29 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/23 14:35:04 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstremove_if(t_list **head, void *data_ref,
				int (*cmp)(void *, void *), void (*free_fct)(void *))
{
	t_list	*curr;
	t_list	*prev;

	if (head == NULL || *head == NULL)
		return ;
	curr = *head;
	prev = *head;
	while (curr != NULL)
	{
		if (cmp(curr->content, data_ref) == 0)
		{
			prev->next = curr->next;
			free_fct(curr->content);
		}
		prev = curr;
		curr = curr->next;
	}
}
