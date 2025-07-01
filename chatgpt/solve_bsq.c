/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/07/01 00:00:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void solve_bsq(t_map *map)
{
    int **dp;
    int max;
    int max_x;
    int max_y;
    int i;
    int j;

    dp = malloc(sizeof(int *) * map->rows);
    i = 0;
    while (i < map->rows)
    {
        dp[i] = malloc(sizeof(int) * ft_strlen(map->data[0]));
        j = 0;
        while (map->data[i][j])
        {
            if (map->data[i][j] == map->obstacle)
                dp[i][j] = 0;
            else if (i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            j++;
        }
        i++;
    }
    max = 0;
    i = 0;
    while (i < map->rows)
    {
        j = 0;
        while (map->data[i][j])
        {
            if (dp[i][j] > max)
            {
                max = dp[i][j];
                max_x = i;
                max_y = j;
            }
            j++;
        }
        i++;
    }

    i = max_x - max + 1;
    while (i <= max_x)
    {
        j = max_y - max + 1;
        while (j <= max_y)
        {
            map->data[i][j] = map->full;
            j++;
        }
        i++;
    }

    i = 0;
    while (i < map->rows)
    {
        free(dp[i]);
        i++;
    }
    free(dp);
}


void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		write(1, map->data[i], ft_strlen(map->data[i]));
		write(1, "\n", 1);
		i = i + 1;
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->data[++i])
		free(map->data[i]);
	free(map->data - 1);
}

void	print_error(void)
{
	write(2, "map error\n", 10);
}
