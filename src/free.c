/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:51:22 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/15 01:16:18 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * @brief Frees memory allocated for a 3D array of strings.
 *
 * This function frees the memory allocated for a 3D array
 * of strings used to store split map content.
 * It iterates through each element of
 * the array and frees the
 * allocated memory to prevent memory leaks.
 *
 * @param split_map_content The 3D array of strings to be freed.
 * @param map_data A pointer to the structure containing map data.
 */
void	ft_free_mega_split(char ***split_map_content, int xmax, int ymax)
{
	int	y_pos;
	int	x_pos;

	y_pos = 0;
	x_pos = 0;
	while (y_pos < ymax)
	{
		x_pos = 0;
		while (x_pos < xmax && split_map_content[y_pos][x_pos])
			free(split_map_content[y_pos][x_pos++]);
		free(split_map_content[y_pos++]);
	}
	free(split_map_content);
}

/**
 * @brief Frees memory allocated for a 2D array of
 * strings.
 *
 * This function frees the memory allocated for a
 * 2D array of strings. It iterates
 * through each element of the array and frees the
 * allocated memory to prevent memory
 * leaks.
 * It also sets the pointer to NULL after
 * freeing to avoid dangling pointers.
 *
 * @param str The 2D array of strings to be freed.
 */
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
