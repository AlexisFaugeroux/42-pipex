/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_here_doc_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:55:00 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/20 14:20:16 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex_bonus.h"

static void	handle_write_error(char *line)
{
	free(line);
	exit(EXIT_FAILURE);
}

static void	handle_open_error(void)
{
	perror("open");
	exit(EXIT_FAILURE);
}

static void	write_input(int fd, char const *limiter)
{
	char			*line;
	size_t const	limiter_len = ft_strlen(limiter);

	while (1)
	{
		ft_putstr_fd(">", 1);
		line = get_next_line(0);
		if (!line)
			exit(EXIT_FAILURE);
		if (write(fd, line, ft_strlen(line)) < 0)
			handle_write_error(line);
		if (ft_strncmp(line, limiter, limiter_len) == 0)
			break ;
		free(line);
	}
	free(line);
}

void	parse_here_doc(t_pipex *pipex, char const *limiter)
{
	int				fd;

	pipex->here_doc = true;
	if (!limiter)
		return ;
	fd = open("here_doc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		handle_open_error();
	write_input(fd, limiter);
	close(fd);
	fd = open("here_doc.tmp", O_RDONLY);
	if (fd < 0)
	{
		if (unlink("here_doc.tmp") < 0)
			perror("unlink");
		handle_open_error();
	}
	pipex->fd_infile = fd;
	pipex->nb_cmds--;
}
