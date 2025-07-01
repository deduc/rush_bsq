/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-c <igomez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:53:01 by igomez-c          #+#    #+#             */
/*   Updated: 2025/07/01 18:23:17 by igomez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_map_files.h"
#include "handle_map_solution.h"
#include "map_utils.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void handle_map_files(char **files)
{
	char	**map;
	int 	rows;
	int		cols;

	files++;
	while (*files)
	{
		if (search_errors(*files) != -1 && read_and_build_map(*files, &map, &rows, &cols) != -1)
		{
			// handle_map_solution(map, rows, cols);
			free_map(map, rows);
		}
		else
		{
			write(2, "Error procesando el fichero\n", 29);
		}
		files++;
	}
}

int	search_errors(char *file)
{
	char	*buffer;

	buffer = open_and_read_file(file);
	if (!buffer)
	{
		write(2, "Error inesperado con uno de los ficheros\n", 41);
		return (-1);
	}
	free(buffer);
	return (1);
}

char	*open_and_read_file(char *file)
{
	int		fd;
	char	*buffer;
	int		bytes_read;

	buffer = malloc(10000);
	if (!buffer)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (NULL);
	}
	bytes_read = read(fd, buffer, 9999);
	if (bytes_read == -1)
	{
		free(buffer);
		close(fd);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	close(fd);
	return (buffer);
}

int read_and_build_map(char *filename, char ***map_ptr, int *rows_ptr, int *cols_ptr)
{
	char *buffer = open_and_read_file(filename);
	if (!buffer)
		return (-1);
	get_map_dimensions(buffer, rows_ptr, cols_ptr);
	*map_ptr = create_map(buffer, *rows_ptr, *cols_ptr);
	free(buffer);
	if (*map_ptr == NULL)
		return (-1);
	return (0);
}

void	free_map(char **map, int rows)
{
	int	i = 0;
	while (i < rows)
		free(map[i++]);
	free(map);
}
