/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/07/01 00:00:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	get_map_info(char *line, t_map *map)
{
	int		len;
	int		i;
	char	*digits;

	len = ft_strlen(line);
	if (len < 4)
		return (0);
	map->empty = line[len - 3];
	map->obstacle = line[len - 2];
	map->full = line[len - 1];
	digits = malloc(len - 2);
	i = 0;
	while (i < len - 3)
	{
		digits[i] = line[i];
		i = i + 1;
	}
	digits[i] = '\0';
	map->rows = ft_atoi(digits);
	free(digits);
	if (map->empty == map->obstacle || map->empty == map->full || map->obstacle == map->full)
		return (0);
	return (1);
}

int	validate_line(char *line, t_map *map)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != map->empty && line[i] != map->obstacle)
			return (0);
		i = i + 1;
	}
	return (1);
}

int	validate_map(t_map *map)
{
	int		len;
	int		i;

	len = ft_strlen(map->data[0]);
	i = 0;
	while (map->data[i])
	{
		if (ft_strlen(map->data[i]) != len)
			return (0);
		if (!validate_line(map->data[i], map))
			return (0);
		i = i + 1;
	}
	if (i != map->rows)
		return (0);
	return (1);
}
