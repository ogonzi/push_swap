/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 09:37:48 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/15 09:39:29 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	ft_buffer_has_line(char *tmp_buffer, int sz)
{
	unsigned int	i;

	i = 0;
	while (tmp_buffer[i] != '\0')
	{
		if (tmp_buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	if (sz == 0)
		return (i);
	return (-1);
}

static int	ft_allocate_and_read(char **tmp_buffer, char **buffer,
			int *sz, int fd)
{
	unsigned int	buf_len;

	if (*buffer)
	{
		buf_len = ft_strlen(*buffer);
		*tmp_buffer = malloc((buf_len + BUFFER_SIZE + 1) * sizeof(char));
		if (!*tmp_buffer)
		{
			free(*buffer);
			return (0);
		}
		ft_strset_gnl(tmp_buffer, 0, buf_len + BUFFER_SIZE + 1);
		ft_strcpy_gnl(tmp_buffer, buffer, buf_len);
		*sz = read(fd, &(*tmp_buffer)[buf_len], BUFFER_SIZE);
		free(*buffer);
		*buffer = NULL;
		return (1);
	}
	*tmp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!*tmp_buffer)
		return (0);
	ft_strset_gnl(tmp_buffer, 0, BUFFER_SIZE + 1);
	*sz = read(fd, *tmp_buffer, BUFFER_SIZE);
	return (1);
}

static int	ft_get_line(char **line, char **tmp_buffer, char **buffer,
			int start_nl)
{
	*line = ft_substr_gnl(tmp_buffer, 0, start_nl);
	if (!(*line))
	{
		free(*tmp_buffer);
		return (0);
	}
	*buffer = ft_substr_gnl(tmp_buffer, start_nl,
			ft_strlen(*tmp_buffer) - start_nl);
	if (!(*buffer))
	{
		free(*tmp_buffer);
		free(*line);
		return (0);
	}
	if (!(*buffer)[0])
	{
		free(*buffer);
		*buffer = NULL;
	}
	free(*tmp_buffer);
	return (1);
}

static int	ft_validate_and_allocate(char **tmp_buffer, char **buffer,
			int *sz, int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!ft_allocate_and_read(tmp_buffer, buffer, sz, fd))
		return (0);
	if (*sz < 0 || (*sz == 0 && *tmp_buffer[0] == '\0'))
	{
		free(*tmp_buffer);
		return (0);
	}
	return (1);
}

/*
 * To obtain the current limit of file descriptors, use: "ulimit -n"
 */

char	*get_next_line(int fd)
{
	static char	*buffer[256];
	char		*tmp_buffer;
	char		*line;
	int			sz;
	int			start_nl;

	if (!ft_validate_and_allocate(&tmp_buffer, &buffer[fd], &sz, fd))
		return (0);
	start_nl = ft_buffer_has_line(tmp_buffer, sz);
	if (start_nl != -1)
	{
		if (!ft_get_line(&line, &tmp_buffer, &buffer[fd], start_nl))
			return (0);
		return (line);
	}
	buffer[fd] = ft_substr_gnl(&tmp_buffer, 0, ft_strlen(tmp_buffer));
	if (!buffer[fd])
		return (0);
	free(tmp_buffer);
	return (get_next_line(fd));
}
