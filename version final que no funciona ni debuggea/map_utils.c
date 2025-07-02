/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-c <igomez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:45:00 by igomez-c          #+#    #+#             */
/*   Updated: 2025/07/02 17:28:33 by igomez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	get_map_dimensions(char *buffer, int *rows, int *cols)
{
	int	i = 0;
	int	col_count = 0;

	*rows = 0;
	*cols = 0;
	while (buffer[i] != '\0')
	{
		if (*rows == 0 && buffer[i] != '\n')
			col_count++;
		if (buffer[i] == '\n')
			(*rows)++;
		i++;
	}
	*cols = col_count;
}

char	**create_map(char *buffer, int rows, int cols)
{
	char	**map;
	int		i = 0;
	int		r = 0;
	int		c = 0;

	map = (char **)malloc(sizeof(char *) * rows);
	if (!map)
		return (NULL);
	while (r < rows)
	{
		map[r] = (char *)malloc(sizeof(char) * (cols + 1));
		if (!map[r])
			return (NULL);
		c = 0;
		while (c < cols && buffer[i] != '\n' && buffer[i] != '\0')
			map[r][c++] = buffer[i++];
		map[r][c] = '\0';
		if (buffer[i] == '\n')
			i++;
		r++;
	}
	return (map);
}

void	print_map(char *map, int size)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			c = map[i * size + j];
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	print_solved_map(char *map, int max_square, int best_row, int best_col, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < max_square)
	{
		j = 0;
		while (j < max_square)
		{
			map[(best_row + i) * size + (best_col + j)] = 'x';
			j++;
		}
		i++;
	}
	print_map(map, size);
}
