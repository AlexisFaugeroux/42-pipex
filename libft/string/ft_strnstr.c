/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:21:39 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/17 19:01:14 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(char const *big, char const *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr_big;
	char	*ptr_little;

	ptr_big = (char *)big;
	ptr_little = (char *)little;
	if (*(ptr_little) == '\0')
		return (ptr_big);
	i = 0;
	while (*(ptr_big + i) && i < len)
	{
		j = 0;
		while (*(ptr_little + j) && *(ptr_big + i + j) && i + j < len)
		{
			if (*(ptr_little + j) != *(ptr_big + i + j))
				break ;
			j++;
		}
		if (j == ft_strlen(little))
			return (ptr_big + i);
		i++;
	}
	return (NULL);
}
