/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:20:28 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/23 14:38:54 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstat(t_list *head, unsigned int nb)
{
	unsigned int	i;
	t_list			*curr;

	if (head == NULL)
		return (NULL);
	curr = head;
	i = 0;
	while (i < nb)
	{
		curr = curr->next;
		if (curr->next == NULL)
			return (NULL);
		i++;
	}
	return (curr);
}
