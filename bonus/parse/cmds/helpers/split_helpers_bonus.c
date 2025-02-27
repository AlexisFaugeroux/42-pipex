/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_helpers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:54:40 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/27 11:29:40 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../pipex_bonus.h"

void	ft_free_split(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
}

bool	skip_sep(const char *s, char sep, int *i)
{
	while (s[*i] && s[*i] == sep)
		(*i)++;
	if (!s[*i])
		return (false);
	return (true);
}
