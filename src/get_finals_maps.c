/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_finals_maps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:56:37 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/15 06:49:59 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_get_finals_maps(char ***split_map_content, t_fdf **map_data, int xmax,
		int ymax)
{
	int		x;
	int		y;
	char	**tmp;

	y = 0;
	while (y < ymax)
	{
		x = 0;
		while (x < xmax && split_map_content[y])
		{
			tmp = ft_split(split_map_content[y][x], ',');
			if (!tmp)
				return (perror("Split Failed"),ft_free_mega_split(split_map_content),
					free_alloc(map_data, ymax), 0);
			map_data[y][x] = (t_fdf){.z = ft_atoi(tmp[0]), .x = x, .y = y};
			if (strchr(split_map_content[y][x], ','))
				map_data[y][x].color = get_the_color(tmp[1]);
			else
				map_data[y][x].color = -1;
			ft_freetab(tmp);
			x++;
		}
		y++;
	}
	return (ft_free_mega_split(split_map_content), 1);
}
