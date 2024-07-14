#include <stdio.h>
#include "gnl/get_next_line.h"
#include "Libft/libft.h"
#include "cub3D.h"
#include <fcntl.h>
#include <stdlib.h>

void	null_all(t_data *data)
{
	data->map = NULL;
}

void	free_all(t_data *data)
{
	if (data->map != NULL)
		free(data->map);
}

void	error(t_data *data, char *str)
{
	ft_putendl_fd(str, 2);
	free_all(data);
	exit(1);
}


int	data_init(t_data *data, int fd, char *map_name)
{
	int     count;
	int     i;
    char    *str;

	count = 0;
	while ((str = get_next_line(fd)) != NULL)
	{
		count++;
		free(str);
	}
	close(fd);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
        return (ft_putendl_fd("fd error", 2), 0);
	data->map = malloc(sizeof(char *) * (count + 1));
    if (!data->map)
		return(0);
	data->map[count] = NULL;
    i = -1;
	while (count)
    {
		str = get_next_line(fd);
        data->map[++i] = malloc(sizeof(char) * ft_strlen(str) + 1);
		free(str);
        count--;
    }
		
	return (1);
}


int	map_scan(t_data *data, char *map_name)
{
	int     fd;

    (void)data;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
        return (ft_putendl_fd("fd error", 2), 0);
	if (!data_init(data, fd, map_name))
        return (close(fd), ft_putendl_fd("malloc error", 2), 0);
    return (free_all(data), 1);
}

int check(char *str)
{
	int size;
	size = ft_strlen(str);
    
    if (str[size - 4] == '.' && str[size - 3] == 'c' &&\
        str[size - 2] == 'u' && str[size - 1] == 'b')
			return (1);
	return (0);
}

int main(int argc, char *argv[])
{
	t_data data;

	null_all(&data);
	if (argc != 2)
		error(&data, "Arg Error");
    if (!check(argv[1]))
        return (ft_putendl_fd("error", 2), 1);
    if (!map_scan(&data, argv[1]))
        return (1);
    return 0;
}
