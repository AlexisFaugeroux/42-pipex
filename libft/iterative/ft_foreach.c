/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:33:05 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/23 14:42:34 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_foreach(void **tab, size_t length, void (*f)(void *))
{
	size_t	i;

	if (!tab || !f || length == 0)
		return ;
	i = 0;
	while (i < length)
	{
		if (tab[i])
			f(tab[i]);
		i++;
	}
}
