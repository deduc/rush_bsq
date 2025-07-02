#ifndef MAP_UTILS_H
# define MAP_UTILS_H

void	get_map_dimensions(char *buffer, int *rows, int *cols);
char	**create_map(char *buffer, int rows, int cols);
void	print_map(char *map, int size);
void	print_solved_map(char *map, int max_square, int best_row, int best_col, int size);

#endif
