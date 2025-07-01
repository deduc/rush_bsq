#include <stdlib.h>

void	get_map_dimensions(char *buffer, int *rows, int *cols)
{
	int	i = 0;
	int	col_count = 0;

	*rows = 0;
	*cols = 0;
	while (buffer[i] != '\0')
	{
		if (*rows == 0 && buffer[i] != '\n')
			col_count++;
		if (buffer[i] == '\n')
			(*rows)++;
		i++;
	}
	*cols = col_count;
}

char	**create_map(char *buffer, int rows, int cols)
{
	char	**map;
	int		i = 0;
	int		r = 0;
	int		c = 0;

	map = (char **)malloc(sizeof(char *) * rows);
	if (!map)
		return (NULL);
	while (r < rows)
	{
		map[r] = (char *)malloc(sizeof(char) * cols);
		if (!map[r])
			return (NULL);
		c = 0;
		while (c < cols && buffer[i] != '\n' && buffer[i] != '\0')
			map[r][c++] = buffer[i++];
		map[r][c] = '\0';
		i++;
		r++;
	}
	return (map);
}
