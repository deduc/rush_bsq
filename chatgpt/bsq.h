/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:00:00 by user42             #+#    #+#             */
/*   Updated: 2025/07/01 00:00:00 by user42            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int		rows;
	char	empty;
	char	obstacle;
	char	full;
	char	**data;
}	t_map;

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
int		ft_atoi(const char *str);

char	**read_map(char *filename);
char	**read_stdin(void);

int		get_map_info(const char *info_line, t_map *map);
int		validate_map(t_map *map);

void	solve_bsq(t_map *map);
void	print_map(t_map *map);
void	free_map(t_map *map);
void	print_error(void);

#endif
