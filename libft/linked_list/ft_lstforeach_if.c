/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstforeach_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:38:33 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/23 14:36:27 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstforeach_if(t_list *lst, void (*f)(void *), void *data_ref,
					int (*cmp)(void *, void *))
{
	if (lst && f)
		return ;
	while (lst)
	{
		if (cmp(lst->content, data_ref) == 0)
			f(lst->content);
		lst = lst->next;
	}
}
