/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:24:33 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/23 14:33:34 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstreverse(t_list **head)
{
	t_list	*curr_1;
	t_list	*curr_2;

	if (head == NULL || *head == NULL)
		return ;
	curr_1 = *head;
	curr_2 = NULL;
	while (*head != NULL)
	{
		curr_1 = (*head)->next;
		(*head)->next = curr_2;
		curr_2 = *head;
		*head = curr_1;
	}
	*head = curr_2;
}
