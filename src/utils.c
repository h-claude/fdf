/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:50:39 by hclaude           #+#    #+#             */
/*   Updated: 2024/03/18 18:41:48 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_check_file_name(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len <= 4)
		return (0);
	if (str[len - 4] == '.')
		if (str[len - 3] == 'f')
			if (str[len - 2] == 'd')
				if (str[len - 1] == 'f')
					return (1);
	return (0);
}

void	ft_stop_process(t_fdf *data, int flag)
{
	if (flag > 0)
		mlx_terminate(data->mlx);
	ft_free_finals_maps(data);
	free(data->angle);
	free(data->coor);
	free(data);
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
