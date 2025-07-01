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

void	handle_map_solution(char map[4][4], int size);
void	get_solution(char map[4][4], int size);
void	print_map(char map[4][4], int size);
int		fill_map_size(char map[4][4], int row, int col, int size, int size_end);
int		try_square(char map[4][4], int row, int col);