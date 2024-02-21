/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:29:15 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/21 17:14:59 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	ft_get_fd(char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (perror("Fail open fd"), -1);
	return (fd);
}

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

static int	ft_split_map_content(char **map_content, t_fdf **map_data, int xmax,
		int ymax)
{
	char	***split_map_content;
	int		y_pos;

	y_pos = 0;
	split_map_content = ft_calloc(sizeof(char **), ymax + 1);
	if (!split_map_content)
		return (perror("Fail alloc split_map_content"), 0);
	while (map_content[y_pos])
	{
		if (y_pos > ymax)
			return (perror("Error with count lines"), 0);
		split_map_content[y_pos] = ft_split(map_content[y_pos], ' ');
		if (!split_map_content[y_pos])
			return (perror("Split Crash"), ft_free_mega_split(split_map_content), ft_freetab(map_content), 0);
		y_pos++;
	}
	return (ft_freetab(map_content), ft_get_finals_maps(split_map_content, map_data, xmax, ymax));
}

static int	ft_getmap(int fd, t_fdf **map_data, int xmax, int ymax)
{
	char	**map_content;
	int		y_pos;

	map_content = ft_calloc(sizeof(char *), ymax + 1);
	if (!map_content)
		return (0);
	y_pos = 0;
	while (y_pos < ymax)
		map_content[y_pos++] = get_next_line(fd);
	if (!ft_checkmap(xmax, ymax, map_content))
		return (perror("Invalid map"), ft_freetab(map_content), 0);
	return (ft_split_map_content(map_content, map_data, xmax, ymax));
}

t_fdf	**alloc(int xmax, int ymax)
{
	t_fdf	**allocd;
	int		y_pos;

	y_pos = 0;
	allocd = (t_fdf **)malloc(sizeof(t_fdf *) * (ymax));
	if (!allocd)
		return (perror("Fail alloc map_data"), NULL);
	while (y_pos < ymax)
	{
		allocd[y_pos] = (t_fdf *)malloc(sizeof(t_fdf) * (xmax));
		if (!allocd[y_pos])
			return(free_alloc(allocd, y_pos),NULL);
		y_pos++;
	}
	return (allocd);
}

t_fdf	**ft_init(char *filepath, t_dimension *dim_map)
{
	t_fdf	**map;
	int		fd;
	int		fd_temp;
	int		xmax;
	int		ymax;

	xmax = 0;
	ymax = 0;
	fd = ft_get_fd(filepath);
	fd_temp = ft_get_fd(filepath);
	if (fd == -1 || fd_temp == -1)
		return (perror("Fail open fd"), NULL);
	if (!ft_count_line_and_point(fd_temp, &xmax, &ymax))
		return (perror("Fichier vide"), close(fd_temp), close(fd), NULL);
	dim_map->xmax = xmax;
	dim_map->ymax = ymax;
	close(fd_temp);
	map = alloc(dim_map->xmax, dim_map->ymax);
	if(!map)
		return (perror("Fail alloc map_data"), NULL);
	if (!ft_getmap(fd, map, dim_map->xmax, dim_map->ymax))
		return (0);
	int y_pos = 0;
	int x_pos = 0;
	while (y_pos < dim_map->ymax)
	{
		x_pos = 0;
		while (x_pos < dim_map->xmax)
		{
			printf("%3d", map[y_pos][x_pos].z);
			x_pos++;
		}
		printf("\n");
		y_pos++;
	}
	close(fd);
	return (map);
}
