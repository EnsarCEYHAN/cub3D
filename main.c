#include <stdio.h>
#include <unistd.h>
#include "gnl/get_next_line.h"
#include "Libft/libft.h"
#include "cub3D.h"
#include <fcntl.h>
#include <stdlib.h>

void	free_all(t_data *data);
void	error(t_data *data, char *str);

void	error(t_data *data, char *str)
{
	ft_putendl_fd(str, 2);
	free_all(data);
	exit(1);
}

void	fd_opener(t_data *data)
{
	close(data->fd);
	data->fd = open(data->map_name, O_RDONLY);
	if (data->fd == -1)
        error(data, "fd error");
}

void	null_all(t_data *data, char *name)
{
	data->map = NULL;
	data->map_name = name;
}

void	free_all(t_data *data)
{
	int i;

	i = -1;
	while (data->map[++i] != NULL)
		free(data->map[i]);
	if (data->map != NULL)
		free(data->map);
}

void	data_init(t_data *data)
{
	int     count;
	int     i;
    char    *str;

	count = 0;
	while ((str = get_next_line(data->fd)) != NULL)
	{
		count++;
		free(str);
	}
	close(data->fd);
	fd_opener(data);
	data->map = malloc(sizeof(char *) * (count + 1));
    if (!data->map)
		error(data, "malloc error");
	data->map[count] = NULL;
    i = -1;
	while (count)
    {
		str = get_next_line(data->fd);
        data->map[++i] = malloc(sizeof(char) * ft_strlen(str) + 1);
		if (!data->map[i])
			error(data, "Malloc Error");
		free(str);
        count--;
    }
}


void	map_scan(t_data *data)
{
	char	*map_line;
	char	*line;
	char	*tmp;

	data->fd = open(data->map_name, O_RDONLY);
	if (data->fd == -1)
        error(data, "fd error");
		
	data_init(data);

	fd_opener(data);
	map_line = ft_strdup("");
	while ((line = get_next_line(data->fd)) != NULL)
	{
		tmp = map_line;
		map_line = ft_strjoin(tmp, line);
		if (!map_line)
			error(data, "ft_strjoin Error");
		free(tmp);
		free(line);
	}
	data->map = ft_split(map_line, '\n');
	int i = -1;
	while (data->map[++i])					// ilk satırları ayır.
		printf("%s\n", data->map[i]);
	free(map_line);
}

void check(t_data *data, char *str)
{
	int size;
	size = ft_strlen(str);
    
    if (str[size - 4] != '.' || str[size - 3] != 'c' ||\
        str[size - 2] != 'u' || str[size - 1] != 'b')
			error(data, "extension error");
}

int main(int argc, char *argv[])
{
	t_data data;

	null_all(&data, argv[1]);
	if (argc != 2)
		error(&data, "Arg Error");
    check(&data, argv[1]);
    map_scan(&data);
    return (free_all(&data), 0);
}
