/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/07/01 00:00:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>

char	*read_file(int fd)
{
	char	*buffer;
	char	*temp;
	char	*result;
	int		bytes;

	buffer = malloc(sizeof(char) * (BUF_SIZE + 1));
	result = malloc(sizeof(char));
	result[0] = '\0';
	bytes = read(fd, buffer, BUF_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		temp = malloc(ft_strlen(result) + ft_strlen(buffer) + 1);
		ft_strcpy(temp, result);
		ft_strcpy(temp + ft_strlen(result), buffer);
		free(result);
		result = temp;
		bytes = read(fd, buffer, BUF_SIZE);
	}
	free(buffer);
	return (result);
}

char	**split_lines(char *buffer)
{
	char	**lines;
	int		count;
	int		i;
	int		j;
	int		k;

	i = 0;
	count = 1;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			count = count + 1;
		i = i + 1;
	}
	lines = malloc(sizeof(char *) * (count + 1));
	i = 0;
	j = 0;
	while (j < count)
	{
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			i = i + 1;
		lines[j] = malloc(i + 1);
		k = 0;
		while (k < i)
		{
			lines[j][k] = buffer[k];
			k = k + 1;
		}
		lines[j][k] = '\0';
		buffer = buffer + i + 1;
		j = j + 1;
	}
	lines[j] = 0;
	return (lines);
}

char	**read_map(char *filename)
{
	int		fd;
	char	*buffer;
	char	**lines;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	buffer = read_file(fd);
	close(fd);
	lines = split_lines(buffer);
	free(buffer);
	return (lines);
}

char	**read_stdin(void)
{
	char	*buffer;
	char	**lines;

	buffer = read_file(0);
	lines = split_lines(buffer);
	free(buffer);
	return (lines);
}
