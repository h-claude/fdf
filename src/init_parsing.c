/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:29:15 by hclaude           #+#    #+#             */
/*   Updated: 2024/03/19 12:06:02 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * @brief Opens a file and retrieves its file descriptor.
 *
 * This function opens the specified file at the given `filepath` and retrieves
 * the file descriptor. It also performs an additional opening to count the lines
 * and points in the file using `ft_count_line_and_point` function.
 *
 * @param filepath The path to the file to be opened.
 * @param data A pointer to the structure containing map data.
 *
 * @return The file descriptor if successful, or -1 on failure.
 * 		   In case of failure,
 *         it also prints an error message using perror.
 */
static int	ft_get_fd(char *filepath, t_fdf *data)
{
	int	fd;
	int	fd_temp;

	fd = open(filepath, O_RDONLY);
	fd_temp = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		if (fd_temp > 0)
			close(fd_temp);
		return (-1);
	}
	if (fd_temp == -1)
	{
		if (fd > 0)
			close(fd);
		return (-1);
	}
	if (!ft_count_line_and_point(fd_temp, data))
		return ((void)close(fd), -1);
	return (fd);
}

/**
 * @brief Checks the validity of the map by comparing
 * the number of points per line.
 *
 * This function compares the number of points per line
 * in the map with the specified value `nbr_point`.
 * If the number of points does not match, it returns 0; otherwise,
 * it returns 1.
 *
 * @param nbr_point The expected number of points per line.
 * @param nbr_line The total number of lines in the map.
 * @param map The array containing the map content.
 *
 * @return 1 if the map is valid, 0 otherwise.
 */
static int	ft_checkmap(int nbr_point, int nbr_line, char **map)
{
	int	y_pos;

	y_pos = 0;
	while (y_pos < nbr_line)
	{
		if (nbr_point != ft_count_point(map[y_pos], ' '))
			return (0);
		y_pos++;
	}
	return (1);
}

/**
 * @brief Splits the map content into a 3D array of strings.
 *
 * This function splits the content of the map stored in the `map` array
 * into a 3D array of strings using the space character (' ') as a delimiter.
 *
 * @param map The array containing the map content to be split.
 * @param data A pointer to the structure containing map data.
 *
 * @return 1 on success, 0 on failure. In case of failure,
 *         it prints an error message using perror.
 */
static int	ft_splitmap(char **map, t_fdf *data)
{
	char	***splitmap;
	int		y_pos;

	y_pos = 0;
	splitmap = ft_calloc(sizeof(char **), data->ymax);
	if (!splitmap)
		return (freetab(map), 0);
	while (map[y_pos])
	{
		if (y_pos > data->ymax)
			return (freetab(map), free_split(splitmap, data), 0);
		splitmap[y_pos] = ft_split(map[y_pos], ' ');
		if (!splitmap[y_pos])
			return (freetab(map), free_split(splitmap, data), 0);
		y_pos++;
	}
	freetab(map);
	if (!ft_alloc_finals_maps(data))
		return (free_split(splitmap, data), 0);
	return (ft_get_finals_maps(splitmap, data));
}

/**
 * @brief Reads the map content from the file descriptor and processes it.
 *
 * This function reads the map content from the specified
 * file descriptor `fd` and processes it.
 * It ensures the validity of the map using `ft_checkmap` and further
 * splits the map content using `ft_splitmap`.
 *
 * @param fd The file descriptor of the opened file.
 * @param data A pointer to the structure containing map data.
 *
 * @return 1 on success, 0 on failure. In case of failure,
 * it prints an error message using perror.
 */
static int	ft_getmap(int fd, t_fdf *data)
{
	char	**map;
	int		y_pos;

	map = ft_calloc(sizeof(char *), data->ymax + 1);
	if (!map)
		return ((void)close(fd), 0);
	y_pos = 0;
	while (y_pos <= data->ymax)
	{
		map[y_pos] = get_next_line(fd);
		if (!map[y_pos] && y_pos < data->ymax)
		{
			close(fd);
			return (perror("Map invalid"), freetab(map), 0);
		}
		y_pos++;
	}
	map[y_pos] = NULL;
	close(fd);
	if (!ft_checkmap(data->xmax, data->ymax, map))
		return (perror("Map invalid"), freetab(map), 0);
	return (ft_splitmap(map, data));
}

/**
 * @brief Initializes the map data by opening the
 * file and processing its content.
 *
 * This function initializes the map data
 * by opening the specified file using `ft_get_fd`
 * and processing its content using `ft_getmap`.
 * It also frees any allocated memory after
 * processing the map.
 *
 * @param data A pointer to the structure containing map data.
 * @param filepath The path to the file containing the map data.
 *
 * @return 1 on success, 0 on failure.
 */
int	ft_init(t_fdf *data, char *filepath)
{
	int	fd;

	if (!ft_check_file_name(filepath))
		return (perror("Fail open file :/"), 0);
	fd = ft_get_fd(filepath, data);
	if (fd == -1)
		return (0);
	if (!ft_getmap(fd, data))
		return (perror("Parsing failed :/"), 0);
	data->angle = malloc(sizeof(t_angle));
	if (!data->angle)
		return (perror("fail alloc angle_data :/"), 0);
	data->coor = malloc(sizeof(t_coor));
	if (!data->coor)
		return (perror("fail alloc coor_data :/"), free(data->angle), 0);
	data->angle->angle_x = 360;
	data->angle->angle_y = 0;
	data->angle->zoom = 1;
	data->angle->trans_x = 0;
	data->angle->trans_y = 0;
	return (1);
}
