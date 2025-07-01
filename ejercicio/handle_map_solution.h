/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_solution.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-c <igomez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:21:24 by igomez-c          #+#    #+#             */
/*   Updated: 2025/07/01 19:32:17 by igomez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_MAP_SOLUTION_H
# define HANDLE_MAP_SOLUTION_H

void	handle_map_solution(char **map, int rows, int cols);
void	get_solution(char **map, int rows, int cols);
int		try_square(char **map, int row, int col, int rows, int cols);
int		fill_map_size(char **map, int row, int col, int size, int size_end);
void	print_map(char **map, int rows, int cols);

#endif
