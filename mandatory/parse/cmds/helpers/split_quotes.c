/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:14:53 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/25 19:01:34 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../pipex.h"

static int	get_word_size(char const *s, char c)
{
	int		j;
	char	quote;

	quote = 0;
	j = 0;
	while (s[j] && s[j] != c)
	{
		if (s[j] == '\'' || s[j] == '\"')
		{
			quote = s[j];
			j++;
			while (s[j] && s[j] != quote)
				j++;
		}
		j++;
	}
	return (j);
}

static int	count_words(char const *s, char c)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break;
		j = get_word_size(&s[i], c);
		if (!(j == 2 && ((s[i] == '\'' && s[i + 1] == '\'')
			|| (s[i] == '\"' && s[i + 1] == '\"'))))
			count++;
		i += j;
	}
	return (count);
}

static void	*ft_write_split(char **split, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (!skip_sep(s, c, &i))
			break ;
		j = get_word_size(&s[i], c);
		if (is_successive_quotes(s, i, j))
			i += j;
		else
		{
			split[k++] = ft_strndup(&s[i], j);
			if (!split[k - 1])
			{
				ft_free_split(split, k - 1);
				return (NULL);
			}
		}
		i += j;
	}
	return ((void *)1);
}

static char	**split_no_quotes(char **split)
{
	int		i;
	char	*tmp;

	i = 0;
	while (split[i])
	{
		tmp = remove_quotes(split[i]);
		if (!tmp)
			return (NULL);
		free(split[i]);
		split[i] = tmp;
		i++;
	}
	return (split);
}

char	**ft_split_quotes(char const *s, char c)
{
	int		words;
	char	**split;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split[words] = 0;
	if (!ft_write_split(split, s, c))
	{
		ft_free_split(split, words);
		return (NULL);
	}
	return (split_no_quotes(split));
}
