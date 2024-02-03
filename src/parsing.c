/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:29:15 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/03 16:19:35 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// free split

void	ft_free_mega_split(char ***split_map_content, t_fdf *map_data)
{
	int	y_pos;
	int	x_pos;

	y_pos = 0;
	x_pos = 0;
	while (y_pos < map_data->ymax)
	{
		x_pos = 0;
		while (x_pos < map_data->xmax && split_map_content[y_pos][x_pos])
			free(split_map_content[y_pos][x_pos++]);
		free(split_map_content[y_pos++]);
	}
	free(split_map_content);
}

// free un tableau

void	ft_freetab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str[i]);
	free(str);
	str = NULL;
}

// count point fait une simulation de split et s'arrette quand \n

int	ft_count_point(char *str, char c)
{
	int	i;
	int	nbstr;

	i = 0;
	nbstr = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if ('\n' == str[i])
			return (nbstr);
		if (str[i] != c && str[i] != '\0')
			nbstr++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (nbstr);
}

// avoir ymax
// faire count line

void	ft_count_line_and_point(int fd, t_fdf *map_data)
{
	char	*temp_line;

	map_data->ymax = 0;
	temp_line = get_next_line(fd);
	if (!temp_line)
		return (perror("Fichier vide"), free(temp_line), (void)close(fd));
	map_data->xmax = ft_count_point(temp_line, ' ');
	while (temp_line)
	{
		map_data->ymax++;
		free(temp_line);
		temp_line = get_next_line(fd);
	}
	close(fd);
	free(temp_line);
}

// faire get fd

int	ft_get_fd(char *filepath, t_fdf *map_data)
{
	int	fd;
	int	fd_temp;

	fd = open(filepath, O_RDONLY);
	fd_temp = open(filepath, O_RDONLY);
	if (fd == -1 || fd_temp == -1)
		return (perror("Fail open fd"), -1);
	ft_count_line_and_point(fd_temp, map_data);
	close(fd_temp);
	return (fd);
}

// faire check map

int	ft_checkmap(int nbr_point, int nbr_line, char **map_content)
{
	int	y_pos;

	y_pos = 0;
	while (y_pos < nbr_line)
	{
		if (nbr_point != ft_count_point(map_content[y_pos], ' '))
			return (0);
		y_pos++;
	}
	return (1);
}

// faire get map color
// faire get map int (z)

void	ft_free_maps(t_fdf *map_data)
{
	int	y_pos;
	int	x_pos;

	y_pos = 0;
	while (y_pos < map_data->ymax)
		free(map_data->pos[y_pos++]);
	free(map_data->pos);
	y_pos = 0;
	while (y_pos < map_data->ymax)
	{
		x_pos = 0;
		while (x_pos < map_data->xmax)
			free(map_data->color[y_pos][x_pos++]);
		free(map_data->color[y_pos]);
		y_pos++;
	}
	free(map_data->color);
}

int	ft_alloc_maps(t_fdf *map_data)
{
	int	y_pos;

	y_pos = 0;
	map_data->pos = malloc(sizeof(int *) * map_data->ymax);
	map_data->color = ft_calloc(sizeof(char **), map_data->ymax + 1);
	if (!map_data->pos || !map_data->color)
		return (free(map_data->color), free(map_data->pos), 0);
	while (y_pos < map_data->ymax)
	{
		map_data->pos[y_pos] = malloc(sizeof(int) * map_data->xmax);
		map_data->color[y_pos] = ft_calloc(sizeof(char *), map_data->xmax + 1);
		if (!map_data->pos[y_pos] || !map_data->color[y_pos])
			return (ft_free_maps(map_data), 0);
		y_pos++;
	}
	return (1);
}

int	ft_get_finals_maps(char ***split_map_content, t_fdf *map_data)
{
	int		x_pos;
	int		y_pos;
	char	**tmp;

	if (!ft_alloc_maps(map_data))
		return (perror("Fail alloc finals maps"), 0);
	y_pos = 0;
	while (y_pos < map_data->ymax - 1)
	{
		x_pos = 0;
		while (x_pos < map_data->xmax - 1 && split_map_content[y_pos])
		{
			tmp = ft_split(split_map_content[y_pos][x_pos], ',');
			map_data->pos[y_pos][x_pos] = ft_atoi(tmp[0]);
			if (strchr(split_map_content[y_pos][x_pos], ','))
				map_data->color[y_pos][x_pos] = ft_strdup(tmp[1]);
			else
				map_data->color[y_pos][x_pos] = NULL;
			ft_freetab(tmp);
			x_pos++;
		}
		y_pos++;
	}
	return (ft_free_mega_split(split_map_content, map_data), 1);
}
// split la map

int	ft_split_map_content(char **map_content, t_fdf *map_data)
{
	char	***split_map_content;
	int		y_pos;

	y_pos = 0;
	split_map_content = ft_calloc(sizeof(char **), map_data->ymax + 1);
	if (!split_map_content)
		return (perror("Fail alloc split_map_content"), 0);
	while (map_content[y_pos])
	{
		split_map_content[y_pos] = ft_split(map_content[y_pos], ' ');
		y_pos++;
	}
	ft_freetab(map_content);
	return (ft_get_finals_maps(split_map_content, map_data));
}

// faire get the map

int	ft_getmap(int fd, t_fdf *map_data)
{
	char	**map_content;
	int		y_pos;

	map_content = ft_calloc(sizeof(char *), map_data->ymax + 1);
	if (!map_content)
		return (free(map_content), 0);
	y_pos = 0;
	while (y_pos <= map_data->ymax)
	{
		map_content[y_pos] = get_next_line(fd);
		y_pos++;
	}
	if (!ft_checkmap(map_data->xmax, map_data->ymax, map_content))
		return (perror("Map invalid"), ft_freetab(map_content), 0);
	return (ft_split_map_content(map_content, map_data));
}

// faire fonction qui free

// faire ft_init

int	ft_init(t_fdf *map_data, char *filepath)
{
	int	fd;

	fd = ft_get_fd(filepath, map_data);
	if (fd == -1)
		return (0);
	if (!ft_getmap(fd, map_data))
		return (0);
	ft_free_maps(map_data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fdf	*map_data;

	map_data = malloc(sizeof(t_fdf));
	if (ft_init(map_data, argv[1]))
		printf("good !\n");
	free(map_data);
}
