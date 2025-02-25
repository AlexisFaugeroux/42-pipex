/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_outfile_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:15:31 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/24 18:47:12 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex_bonus.h"

static void	handle_open_error(char *input)
{
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(input, 2);
	ft_putstr_fd("\n", 2);
}

void	parse_outfile(t_pipex *pipex, char *input)
{
	int	fd;

	if (access(input, F_OK) == 0)
	{
		if (access(input, W_OK) == -1)
		{
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd(": ", 2);
			ft_putstr_fd(input, 2);
			ft_putstr_fd("\n", 2);
		}
		if (pipex->here_doc)
			fd = open(input, O_WRONLY | O_APPEND, 0644);
		else
			fd = open(input, O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
			handle_open_error(input);
	}
	else
	{
		fd = open(input, O_CREAT | O_WRONLY, 0644);
		if (fd == -1)
			handle_open_error(input);
	}
	pipex->fd_outfile = fd;
}
