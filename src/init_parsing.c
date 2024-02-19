/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:29:15 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/19 16:34:22 by hclaude          ###   ########.fr       */
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
		if (y_pos > ymax) // y_pos etait superieur a ymax et ca fait boum
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
	while (y_pos <= ymax)
		map_content[y_pos++] = get_next_line(fd);
	if (!ft_checkmap(xmax, ymax, map_content))
		return (perror("Map invalid"), ft_freetab(map_content), 0);
	return (ft_split_map_content(map_content, map_data, xmax, ymax));
}

t_fdf	**alloc(int xmax, int ymax)
{
	t_fdf	**allocd;

	allocd = (t_fdf **)malloc(sizeof(t_fdf *) * (ymax + 1));
	if (!allocd)
		return (perror("Fail alloc map_data"), NULL);
	ymax++;
	while (ymax > 0)
	{
		allocd[--ymax] = (t_fdf *)malloc(sizeof(t_fdf) * (xmax + 1));
		if (!allocd[ymax])
			return(free_alloc(allocd, ymax),NULL);
	}
	return (allocd);
}

t_fdf	**ft_init(char *filepath, int *y)
{
	t_fdf	**map;
	int		fd;
	int		fd_temp;
	int		xmax;
	int		ymax;
	int		y_pos;
	int		x_pos;

	xmax = 0;
	ymax = 0;
	fd = ft_get_fd(filepath);
	fd_temp = ft_get_fd(filepath);
	if (fd == -1 || fd_temp == -1)
		return (perror("Fail open fd"), NULL);
	if (!ft_count_line_and_point(fd_temp, &xmax, &ymax))
		return (perror("Fichier vide"), close(fd_temp), close(fd), NULL);
	printf("%d et %d\n", ymax, xmax);
	close(fd_temp);
	*y = ymax;
	map = alloc(xmax, ymax);
	if(!map)
		return (perror("Fail alloc map_data"), NULL);
	if (!ft_getmap(fd, map, xmax, ymax))
		return (0);
	printf("TEST 1\n");
	y_pos = 0;
	x_pos = 0;
	while (y_pos < ymax)
	{
		x_pos = 0;
		while (x_pos < xmax)
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
