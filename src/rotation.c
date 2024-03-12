/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:12:22 by hclaude           #+#    #+#             */
/*   Updated: 2024/03/12 17:56:41 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_modcoord(t_fdf *map_data, int flag)
{
	if (flag == 0)
		map_data->angle_data->angle_y += 3;
	if (flag == 1)
		map_data->angle_data->angle_y -= 3;
	if (flag == 2)
		map_data->angle_data->angle_x += 3;
	if (flag == 3)
		map_data->angle_data->angle_x -= 3;
	if (flag == 4)
		map_data->angle_data->zoom += 0.05;
	if (flag == 5 && map_data->angle_data->zoom > 0.5)
		map_data->angle_data->zoom -= 0.05;
	ft_clearimage(map_data->image);
}

void	ft_inputs(t_fdf *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		ft_modcoord(data, 0);
		printf("angley = %f\n", data->angle_data->angle_y);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		ft_modcoord(data, 1);
		printf("angley = %f\n", data->angle_data->angle_y);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		ft_modcoord(data, 2);
		printf("anglex = %f\n", data->angle_data->angle_x);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		ft_modcoord(data, 3);
		printf("anglex = %f\n", data->angle_data->angle_x);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
	{
		ft_modcoord(data, 4);
		printf("zoom = %f\n", data->angle_data->zoom);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_CONTROL))
	{
		ft_modcoord(data, 5);
		printf("zoom = %f\n", data->angle_data->zoom);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		ft_stop_process(data, 1);
}


void rotation_x(int y, int z, t_fdf *data, t_coor *coord)
{
	int y_n = coord->y;
	int z_n = coord->z;

	int rad = data->angle_data->angle_x;
	y_n = (y * cos(rad)) - (z * sin(rad));
	z_n = (y * sin(rad)) + (z * cos(rad));
}

void rotation_y(int x, int z, t_fdf *data, t_coor *coord)
{
	int x_n = coord->x;
	int z_n = coord->z;

	int rad = data->angle_data->angle_y;
	x_n = (x * cos(rad)) + (z * sin(rad));
	z_n = (-x * sin(rad)) + (z * cos(rad));
}

void rotation_z(int x, int y, t_fdf *data, t_coor *coord)
{
	int x_n = coord->x;
	int y_n = coord->y;

	int rad = data->angle_data->angle_z;
	x_n = (x * cos(rad)) - (y * sin(rad));
	y_n = (x * sin(rad)) + (y * cos(rad));
}

t_coor	*rotation(t_fdf *data, int x, int y)
{
	t_coor	*coord;
	coord = malloc(sizeof(t_coor));

	rotation_x(y, data->pos[y][x], data, coord);
	rotation_y(x, coord->z, data, coord);
	rotation_z(coord->x, coord->y, data, coord);
}

//Conversion coordonee y vers isometrique
//int32_t	planey(int x, int y, t_fdf *data)
//{
//	float	angle;
//	float	zoom;
//	int		z;

//	z = data->pos[y][x];
//	zoom = data->angle_data->zoom;
//	angle = data->angle_data->angle_y * (M_PI / 180);
//	return (((y + (x + z) * sin(angle)) * zoom) + data->centre_y);
//}

////Conversion coordonee x vers isometrique
//int32_t	planex(int x, int y, t_fdf *data)
//{
//	float	angle;
//	float	zoom;
//	int		z;

//	z = data->pos[y][x];
//	zoom = data->angle_data->zoom;
//	angle = data->angle_data->angle_x * (M_PI / 180);
//	return ((((x - z) * cos(angle)) * zoom) + data->centre_x);
}

//int32_t planey(int x, int y, t_fdf *data)
//{
//	float angle;

//	angle = data->angle_data->angle_y * (M_PI / 180);
//	return ((-y * sin(angle) - data->pos[y][x] * sin(angle)) * data->angle_data->zoom);
//}

////Conversion coordonee x vers isometrique
//int32_t planex(int x, int y, t_fdf *data)
//{
//	float angle;

//	angle = data->angle_data->angle_x * (M_PI / 180);
//	return ((x + cos(angle) * data->pos[y][x] - cos(angle) * y) * data->angle_data->zoom);
//}

//destination.x = source.x + cos(angle) * source.z - cos(angle) * source.y
//destination.y = -source.y * sin(angle) - source.z * sin(angle)