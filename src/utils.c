/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:50:39 by hclaude           #+#    #+#             */
/*   Updated: 2024/03/12 15:50:01 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_stop_process(t_fdf *map, int flag)
{
	if (flag > 0)
		mlx_terminate(map->mlx);
	printf("ok\n");
	ft_free_finals_maps(map);
	printf("ok 1\n");
	free(map->angle_data);
	printf("ok 2\n");
	free(map);
	printf("ok 3\n");
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
