#ifndef     CUB3D_H
# define    CUB3D_H


#include <stdio.h> // delete it when push

typedef struct s_data
{
	char 	**map;
	char	*map_name;
	int		fd;
	char	**texture;
} t_data;


// utils

void	free_all(t_data *data);
void	error(t_data *data, char *str);
void	check(t_data *data, char *str);


// main

void	map_scan(t_data *data, int count, char *str);

#endif