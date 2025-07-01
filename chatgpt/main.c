/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/07/01 00:00:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	process_file(char *filename)
{
	char	**lines;
	t_map	map;
	int		valid;

	lines = read_map(filename);
	if (!lines)
	{
		print_error();
		return;
	}
	valid = get_map_info(lines[0], &map);
	if (!valid)
	{
		print_error();
		return;
	}
	map.data = &lines[1];
	if (!validate_map(&map))
	{
		print_error();
		return;
	}
	solve_bsq(&map);
	print_map(&map);
	free_map(&map);
}

void	process_input(void)
{
	char	**lines;
	t_map	map;
	int		valid;

	lines = read_stdin();
	if (!lines)
	{
		print_error();
		return;
	}
	valid = get_map_info(lines[0], &map);
	if (!valid)
	{
		print_error();
		return;
	}
	map.data = &lines[1];
	if (!validate_map(&map))
	{
		print_error();
		return;
	}
	solve_bsq(&map);
	print_map(&map);
	free_map(&map);
}

int	main(int argc, char **argv)
{
	int	index;

	index = 1;
	if (argc == 1)
	{
		process_input();
		return (0);
	}
	while (index < argc)
	{
		process_file(argv[index]);
		if (index + 1 < argc)
			write(1, "\n", 1);
		index = index + 1;
	}
	return (0);
}
