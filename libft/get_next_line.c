/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:24:08 by cvine             #+#    #+#             */
/*   Updated: 2022/01/14 20:13:36 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*get_saved(int fd, char *buf, char *saved)
{
	int	rd_bytes;

	rd_bytes = 1;
	while (!(find_newline(saved)) && rd_bytes)
	{
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if ((!rd_bytes && !saved) || rd_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd_bytes] = '\0';
		saved = gnl_strjoin(saved, buf);
	}
	free(buf);
	return (saved);
}

static char	*get_line(char *saved, char **line)
{
	size_t	len;

	if (!saved)
		return (NULL);
	len = 0;
	while (saved[len] != '\n' && saved[len])
		len++;
	if (saved[len] == '\n')
		len++;
	*line = malloc(sizeof(char) * (len + 1));
	if (!(*line))
		return (NULL);
	ft_strlcpy(*line, saved, len + 1);
	return (*line);
}

static char	*trim_saved(char *saved)
{
	char	*tmp;
	char	*nl_ptr;

	tmp = saved;
	nl_ptr = find_newline(saved);
	if (nl_ptr++)
	{
		if (!(*nl_ptr))
			saved = NULL;
		else
			saved = ft_strdup(nl_ptr);
	}
	else
		saved = NULL;
	free(tmp);
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	saved = get_saved(fd, buf, saved);
	if (!saved)
		return (saved);
	line = get_line(saved, &line);
	saved = trim_saved(saved);
	return (line);
}
