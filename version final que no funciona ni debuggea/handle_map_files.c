/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-c <igomez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:53:01 by igomez-c          #+#    #+#             */
/*   Updated: 2025/07/02 18:32:36 by igomez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_map_files.h"
#include "handle_map_solution.h"
#include "map_utils.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	read_map(char *file, int *size, char map_chars[3])
{
	char	*buffer;
	int		is_ok;

	is_ok = 1;
	if (open_and_read_file(file, buffer) == -1 || search_errors(buffer, size, map_chars) == -1)
	{
		free(buffer);
		is_ok = -1;
	}
	return (is_ok);
}

int open_and_read_file(char *file, char *buffer)
{
	int		fd;
	int		bytes_read;

	buffer = malloc(10000);
	if (!buffer)
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (-1);
	}
	bytes_read = read(fd, buffer, 9999);
	if (bytes_read == -1)
	{
		free(buffer);
		close(fd);
		return (-1);
	}
	buffer[bytes_read] = '\0';
	close(fd);
	return (1);
}

int	search_errors(char *buffer, int *size, char map_chars[3])
{
	int	i;
	int	j;
	int	char_map_type;

	i = 0;
	j = 0;
	char_map_type = 0;
	while (buffer[i] != '\n')
	{
		get_map_parameters(buffer, size, map_chars, i, char_map_type);
		i++;
	}
	i++;
	while (buffer[i] != '\0')
	{
		if (check_parameters_in_map(buffer[i], size, map_chars) == -1)
			return (-1);
		if (buffer[i] != '\n')
			j++;
		i++;
	}
	if (*size * *size != j)
		return (-1);
	return (1);
}

void	get_map_parameters(char *buffer, int *size, char map_chars[3], int i, int *char_pos)
{
	if (buffer[i] >= 49 && buffer[i] <= 57)
		*size = buffer[i];
	else if ((buffer[i] >= 32 && buffer[i] <= 48) || (buffer[i] >= 58 && buffer[i] <= 126))
	{
		map_chars[*char_pos] = buffer[i];
		*char_pos++;
	}
	else
		buffer[i] = 0;
}

int	check_parameters_in_map(char buffer_char, int *size, char map_chars[3])
{
	if (buffer_char != map_chars[0] && buffer_char != map_chars[1])
		return (-1);
	if (buffer_char == map_chars[2])
		return (-1);
	return (1);
}

int	build_map(char *filename, char ***map_ptr, int *map_size, char *buffer)
{
	int	row;
	int	col;

	row = *map_size;
	col = *map_size;
	*map_ptr = create_map(buffer, row, col);
	free(buffer);
	if (*map_ptr == NULL)
		return (-1);
	return (0);
}

void	free_map(char **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(map[i++]);
	free(map);
}

void	handle_map_files(char **files)
{
	char	**map;
	char	*buffer[1024];
	int		size;
	char	map_chars[3];

	size = 0;
	files++;
	while (*files)
	{
		if (read_map(*files, size, map_chars) == -1)
			write(2, "map error lalala\n", 20);
		else
		{
			if (build_map(*files, &map, size, *buffer) == -1)
				write(2, "build error", 12);
			else
				handle_map_solution(map, size);
			free_map(map, size);
		}
		files++;
	}
}
