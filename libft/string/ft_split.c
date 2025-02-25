/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:23:09 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/24 19:02:31 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (j == 0 && s[i] != c)
		{
			count++;
			j = 1;
		}
		else if (s[i] == c)
			j = 0;
		i++;
	}
	return (count);
}

static void	ft_free_split(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
}

static void	*ft_write_split(char **split, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = i;
			while (s[j] != c && s[j])
				j++;
			split[k++] = ft_strndup(&s[i], j - i);
			if (!split[k - 1])
			{
				ft_free_split(split, k - 1);
				return (NULL);
			}
			i = j;
		}
	}
	return ((void *)1);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**split;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split[words] = 0;
	if (!ft_write_split(split, s, c))
	{
		ft_free_split(split, words);
		return (NULL);
	}
	return (split);
}
