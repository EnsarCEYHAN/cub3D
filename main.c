#include "cub3D.h"
#include <stddef.h>

void	starter(t_data *data, char *name)
{
	data->map = NULL;
	data->texture = NULL;
	data->fd = -2;
	data->map_name = name;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	starter(&data, argv[1]);
	if (argc != 2)
		error(&data, "Arg Error");
    check(&data, argv[1]);
	map_scan(&data, 0, NULL);
    return (free_all(&data), 0);
}
