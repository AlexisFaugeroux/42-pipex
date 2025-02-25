/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:01:13 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/20 12:02:01 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../pipex_bonus.h"

char	*get_env_path(char **envp)
{
	char	*path;
	int		i;

	if (!envp)
		return (NULL);
	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(envp[i] + 5);
			if (!path)
				return (NULL);
			break ;
		}
		i++;
	}
	return (path);
}

static char	*format_searched_path(char *prefix, char *cmd)
{
	char	*path;
	char	*tmp;

	tmp = ft_strjoin("/", cmd);
	if (!tmp)
		return (NULL);
	path = ft_strjoin(prefix, tmp);
	if (!path)
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (path);
}

static char	*find_path(char *cmd, char **paths)
{
	int		i;
	char	*target;

	i = 0;
	while (paths[++i])
	{
		target = format_searched_path(paths[i], cmd);
		if (!target)
		{
			free_paths(paths, i - 1);
			return (NULL);
		}
		if (access(target, X_OK) == 0)
		{
			free_paths(paths, -1);
			return (target);
		}
		free(target);
	}
	free_paths(paths, -1);
	return (NULL);
}

char	*get_path(char *env_path, char *cmd)
{
	char	**paths;

	if (!env_path)
		return (NULL);
	paths = ft_split(env_path, ':');
	if (!paths)
		return (NULL);
	return (find_path(cmd, paths));
}

char	*get_path_wdir(char *cmd)
{
	char	*path;

	if (access(cmd, X_OK) == -1)
		return (NULL);
	path = ft_strdup(cmd);
	if (!path)
		return (NULL);
	return (path);
}
