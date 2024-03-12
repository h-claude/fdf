/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_finals_maps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:56:37 by hclaude           #+#    #+#             */
/*   Updated: 2024/03/12 15:19:09 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * @brief Frees memory allocated for the final
 * maps in the map data structure.
 *
 * This function frees the memory allocated
 * for the position and color maps within
 * the map data structure.
 * It iterates through the arrays and frees each allocated
 * block of memory to prevent memory leaks.
 *
 * @param map_data A pointer to the structure containing map data.
 */
void	ft_free_finals_maps(t_fdf *map_data)
{
	int	y_pos;

	y_pos = 0;
	while (y_pos < map_data->ymax)
		free(map_data->pos[y_pos++]);
	free(map_data->pos);
	y_pos = 0;
	while (y_pos < map_data->ymax)
		free(map_data->color[y_pos++]);
	free(map_data->color);
}

/**
 * @brief Allocates memory for the final maps in
 * the map data structure.
 *
 * This function allocates memory for the position
 * and color maps within the map data structure.
 * It uses the dimensions specified in `map_data` to create arrays
 * for positions and a 2D array for colors.
 *
 * @param map_data A pointer to the structure containing map data.
 *
 * @return 1 on success, 0 on failure. In case of failure, it frees any allocated
 *         memory and returns 0.
 */
int	ft_alloc_finals_maps(t_fdf *map_data)
{
	int	y_pos;

	y_pos = 0;
	map_data->pos = malloc(sizeof(int *) * map_data->ymax);
	map_data->color = malloc(sizeof(int *) * map_data->ymax);
	if (!map_data->pos || !map_data->color)
		return (free(map_data->color), free(map_data->pos), 0);
	while (y_pos < map_data->ymax)
	{
		map_data->pos[y_pos] = ft_calloc(sizeof(int), map_data->xmax);
		map_data->color[y_pos] = ft_calloc(sizeof(int32_t), map_data->xmax);
		if (!map_data->pos[y_pos] || !map_data->color[y_pos])
			return (ft_free_finals_maps(map_data), 0);
		y_pos++;
	}
	return (1);
}

/**
 * @brief Processes split map content and populates
 * final maps in the map data structure.
 *
 * This function processes the split map content
 * and populates the final maps within
 * the map data structure, including the
 * position map (`pos`) and the color map (`color`).
 * It also handles memory allocation and frees
 * any temporary storage after processing.
 *
 * @param split_map_content The 3D array containing the split map content.
 * @param map_data A pointer to the structure containing map data.
 *
 * @return 1 on success, 0 on failure. In case of
 * failure, it prints an error message
 *         using perror and frees any allocated memory.
 */
int	ft_get_finals_maps(char ***split_map, t_fdf *data)
{
	int		x_pos;
	int		y_pos;
	char	**tmp;

	y_pos = 0;
	while (y_pos < data->ymax)
	{
		x_pos = 0;
		while (x_pos < data->xmax && split_map[y_pos])
		{
			tmp = ft_split(split_map[y_pos][x_pos], ',');
			if (!tmp)
				return (perror("Split Failed"), free_split(split_map, data), 0);
			data->pos[y_pos][x_pos] = ft_atoi(tmp[0]);
			if (ft_strchr(split_map[y_pos][x_pos], ','))
				data->color[y_pos][x_pos] = get_the_color(tmp[1]);
			else
				data->color[y_pos][x_pos] = -1;
			ft_freetab(tmp);
			x_pos++;
		}
		y_pos++;
	}
	return (free_split(split_map, data), 1);
}
