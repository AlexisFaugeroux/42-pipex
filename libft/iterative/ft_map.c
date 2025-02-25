/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:04:16 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/23 14:44:46 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	**ft_map(void **tab, size_t length, void *(*f)(void *))
{
	size_t	i;
	void	**map;

	if (!tab || !f || length == 0)
		return (NULL);
	map = (void **)malloc(sizeof(void *) * (length + 1));
	if (!map)
		return (NULL);
	map[length] = NULL;
	i = 0;
	while (i < length)
	{
		if (map[i])
			map[i] = f(tab[i]);
		else
			map[i] = NULL;
		i++;
	}
	return (map);
}
