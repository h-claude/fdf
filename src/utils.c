/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:50:39 by hclaude           #+#    #+#             */
/*   Updated: 2024/03/12 15:10:46 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_stop_process(t_fdf *map)
{
	mlx_terminate(map->mlx);
	ft_free_finals_maps(map);
	free(map->angle_data);
	free(map);
	exit(1);
}

void	ft_clearimage(mlx_image_t *image)
{
	int	y_pos;
	int	x_pos;

	y_pos = 0;
	while (y_pos < HEIGHT)
	{
		x_pos = 0;
		while (x_pos < WIDTH)
		{
			mlx_put_pixel(image, x_pos, y_pos, 0xff00FF00);
			x_pos++;
		}
		y_pos++;
	}
}
