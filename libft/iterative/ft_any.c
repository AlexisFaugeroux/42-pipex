/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:11:15 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/23 14:40:04 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_any(void **tab, size_t length, int (*f)(void *))
{
	size_t	i;

	if (!tab || !f || length == 0)
		return (false);
	i = 0;
	while (i < length)
	{
		if (f(*(tab + i)) != 0)
			return (true);
		i++;
	}
	return (false);
}
