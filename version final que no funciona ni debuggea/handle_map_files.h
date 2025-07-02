/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_files.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-c <igomez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:53:10 by igomez-c          #+#    #+#             */
/*   Updated: 2025/07/02 18:28:06 by igomez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef HANDLE_MAP_FILES_H
# define HANDLE_MAP_FILES_H

int		read_map(char *file, int *size, char map_chars[3]);
int		open_and_read_file(char *file, char *buffer);
int		search_errors(char *buffer, int *size, char map_chars[3]);
void	get_map_parameters(char *buffer, int *size, char map_chars[3], int i, int *char_pos);
int		check_parameters_in_map(char buffer_char, int *size, char map_chars[3]);
int		build_map(char *filename, char ***map_ptr, int *map_size, char *buffer);
void	free_map(char **map, int rows);
void	handle_map_files(char **files);

#endif
