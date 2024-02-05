/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_finals_maps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:56:37 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/05 13:58:21 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	ft_free_finals_maps(t_fdf *map_data)
{
	int	y_pos;
	int	x_pos;

	y_pos = 0;
	while (y_pos < map_data->ymax)
		free(map_data->pos[y_pos++]);
	free(map_data->pos);
	y_pos = 0;
	while (y_pos < map_data->ymax)
	{
		x_pos = 0;
		while (x_pos < map_data->xmax)
			free(map_data->color[y_pos][x_pos++]);
		free(map_data->color[y_pos]);
		y_pos++;
	}
	free(map_data->color);
}

static int	ft_alloc_finals_maps(t_fdf *map_data)
{
	int	y_pos;

	y_pos = 0;
	map_data->pos = malloc(sizeof(int *) * map_data->ymax);
	map_data->color = ft_calloc(sizeof(char **), map_data->ymax + 1);
	if (!map_data->pos || !map_data->color)
		return (free(map_data->color), free(map_data->pos), 0);
	while (y_pos < map_data->ymax)
	{
		map_data->pos[y_pos] = malloc(sizeof(int) * map_data->xmax);
		map_data->color[y_pos] = ft_calloc(sizeof(char *), map_data->xmax + 1);
		if (!map_data->pos[y_pos] || !map_data->color[y_pos])
			return (ft_free_finals_maps(map_data), 0);
		y_pos++;
	}
	return (1);
}

int	ft_get_finals_maps(char ***split_map_content, t_fdf *map_data)
{
	int		x_pos;
	int		y_pos;
	char	**tmp;

	if (!ft_alloc_finals_maps(map_data))
		return (perror("Fail alloc finals maps"), 0);
	y_pos = 0;
	while (y_pos < map_data->ymax - 1)
	{
		x_pos = 0;
		while (x_pos < map_data->xmax - 1 && split_map_content[y_pos])
		{
			tmp = ft_split(split_map_content[y_pos][x_pos], ',');
			map_data->pos[y_pos][x_pos] = ft_atoi(tmp[0]);
			if (strchr(split_map_content[y_pos][x_pos], ','))
				map_data->color[y_pos][x_pos] = ft_strdup(tmp[1]);
			else
				map_data->color[y_pos][x_pos] = NULL;
			ft_freetab(tmp);
			x_pos++;
		}
		y_pos++;
	}
	return (ft_free_mega_split(split_map_content, map_data), 1);
}