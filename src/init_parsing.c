/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:29:15 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/07 17:16:23 by hclaude          ###   ########.fr       */
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
 * @param map_data A pointer to the structure containing map data.
 *
 * @return The file descriptor if successful, or -1 on failure.
 * 		   In case of failure,
 *         it also prints an error message using perror.
 */
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
 * @param map_content The array containing the map content.
 *
 * @return 1 if the map is valid, 0 otherwise.
 */
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

/**
 * @brief Splits the map content into a 3D array of strings.
 *
 * This function splits the content of the map stored in the `map_content` array
 * into a 3D array of strings using the space character (' ') as a delimiter.
 *
 * @param map_content The array containing the map content to be split.
 * @param map_data A pointer to the structure containing map data.
 *
 * @return 1 on success, 0 on failure. In case of failure,
 *         it prints an error message using perror.
 */
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

/**
 * @brief Reads the map content from the file descriptor and processes it.
 *
 * This function reads the map content from the specified
 * file descriptor `fd` and processes it.
 * It ensures the validity of the map using `ft_checkmap` and further
 * splits the map content using `ft_split_map_content`.
 *
 * @param fd The file descriptor of the opened file.
 * @param map_data A pointer to the structure containing map data.
 *
 * @return 1 on success, 0 on failure. In case of failure,
 * it prints an error message using perror.
 */
static int	ft_getmap(int fd, t_fdf *map_data)
{
	char	**map_content;
	int		y_pos;

	map_content = ft_calloc(sizeof(char *), map_data->ymax + 1);
	if (!map_content)
		return (free(map_content), 0);
	y_pos = 0;
	while (y_pos <= map_data->ymax)
		map_content[y_pos++] = get_next_line(fd);
	if (!ft_checkmap(map_data->xmax, map_data->ymax, map_content))
		return (perror("Map invalid"), ft_freetab(map_content), 0);
	return (ft_split_map_content(map_content, map_data));
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
 * @param map_data A pointer to the structure containing map data.
 * @param filepath The path to the file containing the map data.
 *
 * @return 1 on success, 0 on failure.
 */
int	ft_init(t_fdf *map_data, char *filepath)
{
	int	fd;

	fd = ft_get_fd(filepath, map_data);
	if (fd == -1)
		return (0);
	if (!ft_getmap(fd, map_data))
		return (0);
	return (1);
}

/**
 * @brief Main function to demonstrate map initialization and processing.
 *
 * This function serves as the main entry point for the program. It allocates
 * memory for the map data, initializes the map using `ft_init`, and prints a
 * success message if the initialization is successful. It also frees the memory
 * allocated for the map data.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of strings containing the command-line arguments.
 *
 * @return 0 on successful execution.
 */
int	main(int argc, char **argv)
{
	t_fdf	*map_data;

	if (argc != 2)
		return(perror("PAS BON"), 0);
	map_data = malloc(sizeof(t_fdf));
	if (ft_init(map_data, argv[1]))
		printf("good !\n");
	int y = 0;
	int x = 0;
	while(y < map_data->ymax)
	{
		x = 0;
		while(x < map_data->xmax)
		{
			printf("(y = %d, x = %d) = %d\n", y, x, map_data->pos[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	ft_free_finals_maps(map_data);
	free(map_data);
}
