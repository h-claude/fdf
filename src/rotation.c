/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:12:22 by hclaude           #+#    #+#             */
/*   Updated: 2024/03/18 17:13:04 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_modcoord(t_fdf *map_data, int flag)
{
	if (flag == 0)
		map_data->angle->angle_y += 3;
	if (flag == 1)
		map_data->angle->angle_y -= 3;
	if (flag == 2)
		map_data->angle->angle_x += 3;
	if (flag == 3)
		map_data->angle->angle_x -= 3;
	if (flag == 4)
		map_data->angle->zoom += 0.05;
	if (flag == 5 && map_data->angle->zoom > 0.5)
		map_data->angle->zoom -= 0.05;
	ft_clearimage(map_data->image);
}

void	ft_inputs(t_fdf *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		ft_modcoord(data, 0);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		ft_modcoord(data, 1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		ft_modcoord(data, 2);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		ft_modcoord(data, 3);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
		ft_modcoord(data, 4);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_CONTROL))
		ft_modcoord(data, 5);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		ft_stop_process(data, 1);
}

//Conversion coordonee y vers isometrique
int32_t	planey(int x, int y, t_fdf *data)
{
	float	angle;
	float	zoom;
	int		z;

	z = data->pos[y][x];
	zoom = data->angle->zoom;
	angle = data->angle->angle_y * (M_PI / 180);
	return (((y + (x + z) * sin(angle)) * zoom) + data->centre_y);
}

//Conversion coordonee x vers isometrique
int32_t	planex(int x, int y, t_fdf *data)
{
	float	angle;
	float	zoom;
	int		z;

	z = data->pos[y][x];
	zoom = data->angle->zoom;
	angle = data->angle->angle_x * (M_PI / 180);
	return ((((x - z) * cos(angle)) * zoom) + data->centre_x);
}
