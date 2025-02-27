/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:41:31 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/27 13:58:38 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	parse_infile(t_pipex *pipex, char *input)
{
	int	fd;

	if (access(input, F_OK) == -1 || access(input, R_OK) == -1)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(input, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return ;
	}
	fd = open(input, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(input, 2);
		ft_putstr_fd("\n", 2);
	}
	pipex->fd_infile = fd;
}
