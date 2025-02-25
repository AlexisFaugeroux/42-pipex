/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:16:06 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/25 18:59:29 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

static void	handle_cmd_not_found_error(char *input)
{
	ft_putstr_fd("Command '", 2);
	ft_putstr_fd(input, 2);
	ft_putstr_fd("' not found\n", 2);
}

static t_cmd	*init_cmd(t_pipex *pipex, char *input)
{
	t_cmd	*cmd;
	char	*env_path;

	if (!input)
		return (NULL);
	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = ft_split_quotes(input, ' ');
	env_path = get_env_path(pipex->env_path);
	cmd->path = get_path(env_path, cmd->args[0]);
	if (!cmd->path)
		cmd->path = get_path_wdir(cmd->args[0]);
	if (!cmd->path)
	{
		handle_cmd_not_found_error(cmd->args[0]);
		free(env_path);
		free_cmd(cmd);
		return (NULL);
	}
	free(env_path);
	return (cmd);
}

void	parse_cmds(t_pipex *pipex, char *argv[])
{
	int		i;

	pipex->cmds = ft_calloc(pipex->nb_cmds + 1, sizeof(t_cmd *));
	if (!(pipex->cmds))
	{
		clean_up_pipex(pipex);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < pipex->nb_cmds)
	{
		if (i == 0 && pipex->fd_infile == -1)
			pipex->cmds[i] = NULL;
		else
			pipex->cmds[i] = init_cmd(pipex, argv[i + 2]);
		i++;
	}
}
