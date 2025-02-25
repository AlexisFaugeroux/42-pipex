/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:27:12 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/23 14:40:59 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_count_if(void **tab, size_t length, int (*f)(void *))
{
	size_t	i;
	int		count;

	if (!tab || !f || length == 0)
		return (0);
	count = 0;
	i = 0;
	while (i < length)
	{
		if (f(*(tab + i)) != 0)
			count++;
		i++;
	}
	return (count);
}
