#ifndef     CUB3D_H
# define    CUB3D_H

# define	W_WIDTH	800
# define	W_HEIGHT 600

#include <stdio.h> // delete it when push

typedef struct s_data
{
	char	**texture;
	char 	**map;
	int		**rgb[2][3];
	char	*map_name;
	void	*mlx;
	void 	*window;
	int		fd;
} t_data;


// utils

void	free_all(t_data *data);
void	error(t_data *data, char *str);
void	check(t_data *data, char *str);


// main

void	map_scan(t_data *data, int count, char *str);

#endif