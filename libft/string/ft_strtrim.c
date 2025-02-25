/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:03:37 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/17 19:01:14 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count_start(const char *s1, const char *set)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s1[i] && ft_is_set(s1[i], set))
	{
		count++;
		i++;
	}
	return (count);
}

static int	ft_count_end(const char *s1, const char *set)
{
	int	i;
	int	count;

	i = ft_strlen(s1) - 1;
	count = 0;
	while (i >= 0 && ft_is_set(s1[i], set))
	{
		count++;
		i--;
	}
	return (count);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t			i;
	size_t const	trim_start = ft_count_start(s1, set);
	size_t const	trim_end = ft_count_end(s1, set);
	size_t			len;
	char			*strtrim;

	if (trim_start + trim_end > ft_strlen(s1))
	{
		strtrim = (char *)malloc(sizeof(char));
		if (!strtrim)
			return (NULL);
		strtrim[0] = '\0';
		return (strtrim);
	}
	len = (ft_strlen(s1) - trim_end - trim_start);
	strtrim = (char *)malloc(sizeof(char) * (len + 1));
	if (!strtrim)
		return (NULL);
	i = 0;
	while (i++ + trim_start < ft_strlen(s1) - trim_end)
	{
		strtrim[i - 1] = s1[i - 1 + trim_start];
	}
	strtrim[len] = '\0';
	return (strtrim);
}
