/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:29:15 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/05 14:01:09 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"


// faire get fd

static int	ft_get_fd(char *filepath, t_fdf *map_data)
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

static int	ft_checkmap(int nbr_point, int nbr_line, char **map_content)
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

// split la map

static int	ft_split_map_content(char **map_content, t_fdf *map_data)
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

static int	ft_getmap(int fd, t_fdf *map_data)
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

int	ft_init(t_fdf *map_data, char *filepath)
{
	int	fd;

	fd = ft_get_fd(filepath, map_data);
	if (fd == -1)
		return (0);
	if (!ft_getmap(fd, map_data))
		return (0);
	ft_free_finals_maps(map_data);
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
