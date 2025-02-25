/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:55:48 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/17 19:01:14 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int		i;
	char	search;
	char	*ptr;

	search = (char)c;
	ptr = (char *)s;
	i = ft_strlen(s) - 1;
	if (search == '\0')
		return (ptr + i + 1);
	while (i >= 0)
	{
		if (*(ptr + i) == search)
			return (ptr + i);
		i--;
	}
	return (NULL);
}
