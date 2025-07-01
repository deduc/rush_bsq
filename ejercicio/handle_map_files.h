/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_files.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-c <igomez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:53:10 by igomez-c          #+#    #+#             */
/*   Updated: 2025/07/01 18:23:21 by igomez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef HANDLE_MAP_FILES_H
# define HANDLE_MAP_FILES_H

void	handle_map_files(char **files);
void	free_map(char **map, int rows);
char	*open_and_read_file(char *file);
int		search_errors(char *files);
int		get_length(char *str);
int		read_and_build_map(char *filename, char ***map_ptr, int *rows_ptr, int *cols_ptr);
char	**create_map(char *buffer, int rows, int cols);
void	get_map_dimensions(char *buffer, int *rows, int *cols);

#endif
