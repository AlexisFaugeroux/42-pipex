/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:24:38 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/17 18:49:30 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	total;

	if (size != 0 && nmemb > ((size_t)-1) / size)
		return (NULL);
	total = size * nmemb;
	alloc = (void *)malloc(total);
	if (!alloc)
		return (NULL);
	ft_memset(alloc, 0, total);
	return (alloc);
}
