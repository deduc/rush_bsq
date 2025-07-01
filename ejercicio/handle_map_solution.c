/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_solution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-c <igomez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:21:20 by igomez-c          #+#    #+#             */
/*   Updated: 2025/07/01 19:38:03 by igomez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "handle_map_solution.h"

void	handle_map_solution(char **map, int rows, int cols)
{
	get_solution(map, rows, cols);
	print_map(map, rows, cols);
}

void	get_solution(char **map, int rows, int cols)
{
	int		i;
	int		j;
	int		max_square_size;
	//todo: char map_aux[X][Y] = full copy del mapa

	i = 0;
	max_square_size = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
            // todo: cuando consiga un valor mayor al tamaño actual del size, sobreescribir el size y cambiar una variable mapa auxiliar
			try_square(map, i, j, rows, cols);
			j++;
		}
		i++;
	}
}

int try_square(char **map, int row, int col, int rows, int cols)
{
	int	size;
	int	size_end;
	int	found_wall;

	size = 1;
	found_wall = 0;
	while (found_wall == 0)
	{
		size_end = size + 1;
		if (fill_map_size(map, row, col, size, size_end) == -1)
		{
			size_end = size;
			return (size);
		}
		size++;
	}

	return (found_wall);
}

int	fill_map_size(char **map, int row, int col, int size, int size_end)
{
	int	i;
	int	j;

	i = row;
	while (i <= size_end)
	{
		j = col;
		while (j <= size_end)
		{
			if (map[i][j] == 'o')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

void	print_map(char **map, int rows, int cols)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			c = map[i][j];
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
