/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:35:20 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/17 19:01:14 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*strjoin;

	len = ft_strlen(s1) + ft_strlen(s2);
	strjoin = (char *)malloc(sizeof(char) * (len + 1));
	if (!strjoin)
		return (NULL);
	ft_strlcpy(strjoin, s1, ft_strlen(s1) + 1);
	ft_strlcat(strjoin, s2, len + 1);
	return (strjoin);
}
