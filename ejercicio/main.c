/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-c <igomez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:34:07 by igomez-c          #+#    #+#             */
/*   Updated: 2025/07/01 18:13:45 by igomez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_map_files.h"
#include <stdio.h>

void	prueba(int n, char **files);

int	main(int n, char **files)
{
	int		index;

	n = n - 1;
	if (n == 0)
	{
		// todo: usuario podrá meter el mapa por consola y luego solucionar
		printf("Error, no hay parametros");
	}
	else
	{
		handle_map_files(files);
	}
	return (0);
}
