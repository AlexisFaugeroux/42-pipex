/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:49:54 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/25 18:53:41 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../pipex.h"

void	set_quote(char c, char *quote)
{
	if (!(*quote) && (c == '\'' || c == '\"'))
		*quote = c;
	else if (*quote && c == *quote)
			*quote = 0;
}

int	get_quotes_nb(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			count++;
		i++;
	}
	return (count);
}

bool	is_successive_quotes(const char *s, int	i, int j)
{
	if (j == 2 && ((s[i] == '\'' && s[i + 1] == '\'')
		|| (s[i] == '\"' && s[i + 1] == '\"')))
		return (true);
	return (false);
}

char	*remove_quotes(char *s)
{
	int			i;
	int			j;
	const int	quotes = get_quotes_nb(s);
	char		*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) - quotes + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != '\'')
		{
			res[j] = s[i];
			j++;
		}
		i++;
	}
	return (res);
}
