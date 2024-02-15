/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_finals_maps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:56:37 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/15 00:52:47 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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

int	ft_get_finals_maps(char ***split_map_content, t_fdf **map_data, int xmax,
		int ymax)
{
	int		x_pos;
	int		y_pos;
	char	**tmp;

	y_pos = 0;
	while (y_pos < ymax)
	{
		x_pos = 0;
		while (x_pos < xmax && split_map_content[y_pos])
		{
			tmp = ft_split(split_map_content[y_pos][x_pos], ',');
			map_data[y_pos][x_pos].z = ft_atoi(tmp[0]);
			map_data[y_pos][x_pos].x = x_pos;
			map_data[y_pos][x_pos].y = y_pos;
			if (strchr(split_map_content[y_pos][x_pos], ','))
				map_data[y_pos][x_pos].color = get_the_color(tmp[1]);
			else
				map_data[y_pos][x_pos].color = -1;
			ft_freetab(tmp);
			x_pos++;
		}
		y_pos++;
	}
	return (ft_free_mega_split(split_map_content, xmax, ymax), 1);
}
