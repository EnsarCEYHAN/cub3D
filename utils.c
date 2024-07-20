#include "cub3D.h"
#include "Libft/libft.h"
#include <stdlib.h> // for free()
#include <unistd.h> // for close()

void	free_all(t_data *data)
{
	int i;

	if (data->map)
	{
		i = -1;
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
	}
	if (data->texture)
	{
		i= -1;
		while (data->texture[++i])
			free(data->texture[i]);
		free(data->texture);
	}
	close(data->fd);
}

void	error(t_data *data, char *str)
{
	ft_putendl_fd(str, 2);
	free_all(data);
	exit(1);
}

void check(t_data *data, char *str)
{
	int size;
	size = ft_strlen(str);
    
    if (str[size - 4] != '.' || str[size - 3] != 'c' ||\
        str[size - 2] != 'u' || str[size - 1] != 'b')
			error(data, "extension error");
}