/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_solution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-c <igomez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:10:55 by igomez-c          #+#    #+#             */
/*   Updated: 2025/07/02 18:19:03 by igomez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "handle_map_solution.h"
#include "map_utils.h"

void	handle_map_solution(char *map, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	solve_map(map, size, i, j);
}

int	try_square(t_mapinfo *info)
{
	int	i;
	int	j;

	i = info->row;
	while (i < info->row + info->max_size)
	{
		if (i >= info->size)
			return (0);
		j = info->col;
		while (j < info->col + info->max_size)
		{
			if (j >= info->size || info->map[i * info->size + j] == 'o')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	update_best_square(t_mapinfo *info,
	int *max_square, int *best_row, int *best_col)
{
	int	current_max;

	current_max = 1;
	while (1)
	{
		info->max_size = current_max;
		if (!try_square(info))
			break ;
		current_max++;
	}
	current_max--;
	if (current_max > *max_square)
	{
		*max_square = current_max;
		*best_row = info->row;
		*best_col = info->col;
	}
	return (0);
}

void	scan_map(t_mapinfo *info, int *max, int *row, int *col)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->size)
	{
		j = 0;
		while (j < info->size)
		{
			if (info->map[i * info->size + j] != 'o')
			{
				info->row = i;
				info->col = j;
				update_best_square(info, max, row, col);
			}
			j++;
		}
		i++;
	}
}

void	solve_map(char *map, int size, int i, int j)
{
	t_mapinfo	info;
	int			max_square;
	int			best_row;
	int			best_col;

	info.map = map;
	info.size = size;
	max_square = 0;
	best_row = 0;
	best_col = 0;
	scan_map(&info, &max_square, &best_row, &best_col);
	print_solved_map(map, max_square, best_row, best_col, size);
}
