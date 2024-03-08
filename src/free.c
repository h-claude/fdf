/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:51:22 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/21 14:25:08 by hclaude          ###   ########.fr       */
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
void	ft_free_mega_split(char ***split_map_content)
{
	int	y_pos;
	int	x_pos;

	y_pos = 0;
	x_pos = 0;
	while (split_map_content[y_pos])
	{
		printf("y = %d et x = %d\n", y_pos, x_pos);
		x_pos = 0;
		while (split_map_content[y_pos][x_pos])
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
	free(str);
	str = NULL;
}

void free_alloc(t_fdf **allocd, int ymax)
{
	int y_pos;

	y_pos = 0;
	while (y_pos < ymax)
		free(allocd[y_pos++]);
	free(allocd);
}
