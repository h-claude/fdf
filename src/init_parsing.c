/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:29:15 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/15 01:27:41 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"


static int	ft_get_fd(char *filepath)//, t_fdf *map_data)
{
	int	fd;
	//int	fd_temp;

	fd = open(filepath, O_RDONLY);
	//fd_temp = open(filepath, O_RDONLY);
	if (fd == -1 )//|| fd_temp == -1)
		return (perror("Fail open fd"), -1);
	//close(fd_temp);
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

static int	ft_split_map_content(char **map_content, t_fdf **map_data, int xmax, int ymax)
{
	char	***split_map_content;
	int		y_pos;
	int err;

	y_pos = 0;
	split_map_content = ft_calloc(sizeof(char **), ymax + 1);
	if (!split_map_content)
		return (perror("Fail alloc split_map_content"), 0);
	while (map_content[y_pos])
	{
		split_map_content[y_pos] = ft_split(map_content[y_pos], ' ');
		if (!split_map_content[y_pos])
		{
			err = 0;
			while (err < y_pos)
				free(split_map_content[err++]);
			return (perror("Split Crash"),free(split_map_content), 0);
		}
		y_pos++;
	}
	ft_freetab(map_content);
	return (ft_get_finals_maps(split_map_content, map_data,xmax, ymax));
}

static int	ft_getmap(int fd, t_fdf **map_data, int xmax, int ymax)
{
	char	**map_content;
	int		y_pos;

	map_content = ft_calloc(sizeof(char *), ymax + 1);
	if (!map_content)
		return (free(map_content), 0);
	y_pos = 0;
	while (y_pos <= ymax)
		map_content[y_pos++] = get_next_line(fd);
	if (!ft_checkmap(xmax, ymax, map_content))
		return (perror("Map invalid"), ft_freetab(map_content), 0);
	return (ft_split_map_content(map_content, map_data,xmax, ymax));
}

t_fdf **alloc(int xmax, int ymax)
{
	t_fdf **allocd;
	
	allocd = (t_fdf **)malloc(sizeof(t_fdf *) * (++ymax + 1));
	while (ymax > 0)
		allocd[--ymax] = (t_fdf *)malloc(sizeof(t_fdf) * (xmax + 1));
	return(allocd);
}



t_fdf	**ft_init(char *filepath, int *y)
{
	t_fdf	**map;
	int	fd;
	int fd_temp;
	int xmax;
	int ymax;

	xmax = 0;
	ymax = 0;	
	
	
	fd = ft_get_fd(filepath);
	fd_temp = ft_get_fd(filepath);
	if (fd == -1 || fd_temp == -1)
		return (0);
	ft_count_line_and_point(fd_temp, &xmax, &ymax);
	*y=ymax;
	close(fd_temp);
	map = alloc(xmax, ymax);
	if (!ft_getmap(fd, map,xmax, ymax))
		return (0);
	close(fd);
	return (map);
}


