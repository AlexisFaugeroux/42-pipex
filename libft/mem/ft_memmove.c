/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:46:02 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/17 18:49:30 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;

	if (dest == src || n == 0)
		return (dest);
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	if (pdest < psrc)
	{
		while (n--)
			*(pdest++) = *(psrc++);
	}
	else
	{
		pdest += n - 1;
		psrc += n - 1;
		while (n--)
			*(pdest--) = *(psrc--);
	}
	return (dest);
}
