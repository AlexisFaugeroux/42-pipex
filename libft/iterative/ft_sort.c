/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:41:40 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/23 14:45:45 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_sort(void **tab, size_t length, int (*cmp)(void *, void *))
{
	size_t	i;
	void	*tmp;

	if (!tab || !cmp || length == 0)
		return ;
	i = 0;
	while (i < length)
	{
		if (i > 0 && cmp(*(tab + i - 1), *(tab + i)) > 0)
		{
			tmp = *(tab + i - 1);
			*(tab + i - 1) = *(tab + i);
			*(tab + i) = tmp;
			i = 1;
		}
		i++;
	}
}
