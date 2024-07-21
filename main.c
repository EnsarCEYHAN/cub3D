#include "cub3D.h"
#include <stddef.h>
#include "minilibx/mlx.h"
#include <stdlib.h> // delete

int rgb(int red, int green, int blue)
{
	int	sum;
	
	sum = 0; 
	sum += red * (256 * 256);
	sum += green * 256;
	sum += blue;

	return (sum); 
}

void enes(t_data *data)
{
	int	i;
	int	j;
	int x;

	x = rgb(data->rgb[0][0], data->rgb[0][1], data->rgb[0][2]);
	printf("%d\n", x);
	data->mlx = mlx_init();
	if (!data->mlx)
		error(data, "Mlx_init Error");
	data->window = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT, "Cub3D");
	if (!data->window)
		error(data, "Mlx_new_window Error");
	i = -1;
	while (++i < W_HEIGHT)
	{
		j = -1;
		while (++j < W_WIDTH)
		{			if (i < W_HEIGHT / 2)
				mlx_pixel_put(data->mlx, data->window, j, i, x);
			else
				mlx_pixel_put(data->mlx, data->window, j, i, 255);
		}
	}
}

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
	(void)argv;
	(void)argc;

	starter(&data, argv[1]);
	if (argc != 2)
		error(&data, "Arg Error");
    check(&data, argv[1]);
	map_scan(&data, 0, NULL);
	enes(&data);
	mlx_loop(&data.mlx);
    return (free_all(&data), 0);
}
