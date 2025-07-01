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

// #include "handle_map_files.h"
#include <stdio.h>
#include <unistd.h>

void	handle_map_files(char **files)
{
	char	mapa[100][100];

	*files++;
	while (*files)
	{
		/*
			buscar errores:
				fichero existe?
				poner posibles errores yks...
			si no hay error:
				get_map_data()
				solucionar mapa
		*/
		search_errors(*files);
		files++;
	}
}

int     search_errors(char *files)
{
	return (1);
}

void    open_and_read_file(char *file)
{
	
}
