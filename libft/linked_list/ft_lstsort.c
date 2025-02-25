/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:43:27 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/27 18:03:38 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstsort(t_list *lst, int (*cmp)(void *, void *))
{
	t_list	*curr;
	t_list	*next;
	bool	sorted;

	if (!lst)
		return ;
	sorted = false;
	while (!sorted)
	{
		sorted = true;
		curr = lst;
		while (curr->next)
		{
			next = curr->next;
			if (cmp(curr->content, next->content) > 0)
			{
				ft_memswap(&(curr->content), &(next->content));
				sorted = false;
			}
			curr = curr->next;
		}
	}
}
