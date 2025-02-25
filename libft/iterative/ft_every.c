/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_every.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:30:33 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/24 10:55:10 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_every(void **tab, size_t length, bool (*f)(void *))
{
	size_t	i;

	if (!tab || !f || length == 0)
		return (false);
	i = 0;
	while (i < length)
	{
		if (f(tab[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}
