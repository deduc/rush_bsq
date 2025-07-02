/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_solution.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-c <igomez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:21:24 by igomez-c          #+#    #+#             */
/*   Updated: 2025/07/02 17:40:56 by igomez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_MAP_SOLUTION_H
# define HANDLE_MAP_SOLUTION_H

typedef struct s_mapinfo
{
	char	*map;
	int		size;
	int		row;
	int		col;
	int		max_size;
}	t_mapinfo;

void	handle_map_solution(char *map, int size);
int		try_square(t_mapinfo *info);
int		update_best_square(t_mapinfo *info, int *max_square, int *best_row, int *best_col);
void	scan_map(t_mapinfo *info, int *max, int *row, int *col);
void	solve_map(char *map, int size, int i, int j);


#endif
