#include <stdio.h>
#include <unistd.h>
#include "GNL/get_next_line.h"
#include "Libft/libft.h"
#include "cub3D.h"
#include <fcntl.h>
#include <stdlib.h>

void	free_all(t_data *data);
void	error(t_data *data, char *str);

void	init_texture(t_data *data)
{
	char	*str;
	int		i;

	data->texture = (char **)malloc(sizeof(char *) * 7);
	if (!data->texture)
		error(data, "malloc error");
	data->texture[6] = NULL;
	i = -1;
	while (++i < 6)
	{
		str = get_next_line(data->fd);
		data->texture[i] = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
		if (!data->texture[i])
			error(data, "Malloc Error");
		ft_strlcpy(data->texture[i], str, ft_strlen(str));
		printf("%s\n", data->texture[i]);
		free(str);
	}
	
}

void	init_data(t_data *data, int count)
{
	int		i;
	char	*str;
	
	i = -1;
	while (count)
    {
		str = get_next_line(data->fd);
		if (!str)
			error(data, "gnl error");
        data->map[++i] = malloc(sizeof(char) * ft_strlen(str) + 1);
		if (!data->map[i])
			error(data, "Malloc Error");
		ft_strlcpy(data->map[i], str, ft_strlen(str));
		free(str);
        count--;
    }
}

void	fd_opener(t_data *data)
{
	if (data->fd == -2)
		close(data->fd);
	data->fd = open(data->map_name, O_RDONLY);
	if (data->fd == -1)
        error(data, "fd error");
}

void	error(t_data *data, char *str)
{
	ft_putendl_fd(str, 2);
	free_all(data);
	exit(1);
}

void	starter(t_data *data, char *name)
{
	data->map = NULL;
	data->texture = NULL;
	data->fd = -2;
	data->map_name = name;
}

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

void	map_scan(t_data *data, int count, char *str)
{
	fd_opener(data);
	while (1)
	{
		str = get_next_line(data->fd); // sıkışırsak burdan kısaltalım.
		if (!str)
			break;
		count++;
		free(str);
	}
	count -= 6;
	fd_opener(data);
	data->map = malloc(sizeof(char *) * (count + 1));
    if (!data->map)
		error(data, "malloc error");
	data->map[count] = NULL;
	init_texture(data);
    init_data(data, count);
}


void check(t_data *data, char *str)
{
	int size;
	size = ft_strlen(str);
    
    if (str[size - 4] != '.' || str[size - 3] != 'c' ||\
        str[size - 2] != 'u' || str[size - 1] != 'b')
			error(data, "extension error");
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
