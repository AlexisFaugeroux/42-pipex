/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:27:33 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/29 21:53:30 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_read(char buffer[FD_SETSIZE][BUFFER_SIZE], int fd)
{
	ssize_t	bytes_read;
	ssize_t	len;

	len = ft_strlen(buffer[fd]);
	bytes_read = 1;
	while (!ft_strchr(buffer[fd], '\n') && bytes_read > 0)
	{
		if (len >= BUFFER_SIZE - 1)
			break ;
		bytes_read = read(fd, buffer[fd] + len, BUFFER_SIZE - len - 1);
		if (bytes_read > 0)
		{
			len += bytes_read;
			buffer[fd][len] = '\0';
		}
		if (ft_strchr(buffer[fd], '\n'))
			return ;
	}
	if (bytes_read == 0 && !ft_strlen(buffer[fd]))
		buffer[fd][0] = '\0';
}

static char	*ft_line(char *buffer)
{
	int		i;

	if (!buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		return (ft_strndup(buffer, i + 1));
	return (ft_strndup(buffer, i));
}

static void	ft_offset(char buffer[], size_t n)
{
	size_t	remaining_len;

	if (n >= ft_strlen(buffer))
	{
		buffer[0] = '\0';
		return ;
	}
	remaining_len = ft_strlen(buffer + n);
	ft_memmove(buffer, buffer + n, remaining_len);
	buffer[remaining_len] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[FD_SETSIZE][BUFFER_SIZE] = {{0}};
	char		*line;
	ssize_t		l_len;

	if (fd < 0 || fd > FD_SETSIZE || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr(buffer[fd], '\n'))
		ft_read(buffer, fd);
	if (!buffer[fd][0])
		return (NULL);
	line = ft_line(buffer[fd]);
	if (!line)
		return (NULL);
	l_len = ft_strlen(line);
	ft_offset(buffer[fd], l_len);
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
