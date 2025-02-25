/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:31:13 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/23 14:43:51 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_is_sort(void **tab, size_t length, int (*cmp)(void *, void *))
{
	size_t	i;
	int		direction;

	if (!tab || !cmp || length == 0)
		return (false);
	if (length == 1)
		return (true);
	i = 1;
	direction = cmp(tab[0], tab[1]);
	while (i < length - 1)
	{
		if (direction < 0 && cmp(tab[i], tab[i + 1]) > 0)
			return (false);
		else if (direction > 0 && cmp(tab[i], tab[i + 1]) < 0)
			return (false);
		i++;
	}
	return (true);
}
