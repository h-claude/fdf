/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:51:22 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/05 13:51:39 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// free split

void	ft_free_mega_split(char ***split_map_content, t_fdf *map_data)
{
	int	y_pos;
	int	x_pos;

	y_pos = 0;
	x_pos = 0;
	while (y_pos < map_data->ymax)
	{
		x_pos = 0;
		while (x_pos < map_data->xmax && split_map_content[y_pos][x_pos])
			free(split_map_content[y_pos][x_pos++]);
		free(split_map_content[y_pos++]);
	}
	free(split_map_content);
}

// free un tableau

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