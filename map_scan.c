#include "cub3D.h"
#include "GNL/get_next_line.h"
#include "Libft/libft.h"

int	white_spaces(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
    	return (1);
	return (0);
}

void	map_control(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = 0;
		while (white_spaces(data->map[i][j]))
			j++;
		if (!data->map[i][j])
			error(data, "line error");
		while (data->map[i][j])
		{
			
			j++;
		}
	}
}

int	alpha_num(char *str, int *flag)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] == '0' || str[i] == '1' || str[i] == 'P') && *flag == 0)
		{
			*flag = 1;
			return (1);
		}
	}
	return (0);
}

void	p_position(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i] != NULL)
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][++j] == 'P')
			{
				data->pp[0] = j;
				data->pp[1] = i;
				printf("konum x: %d, konum y: %d\n", data->pp[0], data->pp[1]);
				return;
			}
			printf("%c", data->map[i][j]);
		}
		printf("\n");
	}
}

void	init_texture(t_data *data)
{
	char	*str;
	int		j;
	int		i;

	data->texture = (char **)malloc(sizeof(char *) * 7);
	if (!data->texture)
		error(data, "malloc error");
	data->texture[6] = NULL;
	i = -1;
	while (++i < 6)
	{
		str = get_next_line(data->fd);
		if (!str)
			error(data, "gnl error");
		j = -1;
		while (str[++j])
			if (str[j] ==  '\n')
				str[j] = '\0';
		data->texture[i] = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
		if (!data->texture[i])
			error(data, "Malloc Error");
		ft_strlcpy(data->texture[i], str, ft_strlen(str) + 1);
		printf("%s\n", data->texture[i]);
		free(str);
	}
}

void	init_rgb(t_data *data, int i)
{	
	int j;
	int	k;
	int	l;
	int sum;

	sum = 0;
	l = -1;
	while (++i <= 5)
	{
		l++;
		j = -1;
		k = -1;
		while (data->texture[i][++j])
		{
			if (('0' <= data->texture[i][j] && data->texture[i][j] <= '9'))
				sum = (sum * 10) + (data->texture[i][j] - 48);
			if (data->texture[i][j] == ',' || !data->texture[i][j + 1])
			{
				data->rgb[l][++k] = sum;
				sum = 0;
			}
		}
	}
}

void	init_data(t_data *data, int count, int i)
{
	int 	flag;
	int		j;
	char	*str;

	flag = 0;
	while (count)
    {
		str = get_next_line(data->fd);
		if (!str)
			error(data, "gnl error");
		if (!alpha_num(str, &flag) && !flag)
		{
			--count;
			free(str);
			continue;
		}
		j = -1;
		while (str[++j])
			if (str[j] == '\n')
				str[j] = '\0';
		data->map[++i] = malloc(sizeof(char) * ft_strlen(str) + 1);
		if (!data->map[i])
			error(data, "Malloc Error");
		ft_strlcpy(data->map[i], str, ft_strlen(str) + 1);
		free(str);
		--count;
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

void	map_scan(t_data *data, int count, char *str)
{
	fd_opener(data);
	while (1)
	{
		str = get_next_line(data->fd);
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
	init_rgb(data, 3);
    init_data(data, count, -1);
	map_control(data);
}
