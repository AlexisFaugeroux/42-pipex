/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:39:20 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/26 18:26:22 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstfind(t_list *head, void *data_ref, int (*cmp)(void *, void *))
{
	t_list	*curr;

	if (!head)
		return (NULL);
	curr = head;
	while (curr != NULL)
	{
		if (cmp(curr->content, data_ref) == 0)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}
