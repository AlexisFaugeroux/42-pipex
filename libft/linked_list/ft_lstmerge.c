/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:41:39 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/23 14:35:40 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstmerge(t_list **head1, t_list *head2)
{
	t_list	*curr1;

	if (head1 == NULL || *head1 == NULL || head2 == NULL)
		return ;
	curr1 = *head1;
	while (curr1->next != NULL)
		curr1 = curr1->next;
	curr1->next = head2;
}
