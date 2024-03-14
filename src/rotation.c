/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deadchicken <deadchicken@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:12:22 by hclaude           #+#    #+#             */
/*   Updated: 2024/03/13 18:10:01 by deadchicken      ###   ########.fr       */
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
		//printf("angley = %f\n", data->angle_data->angle_y);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		ft_modcoord(data, 1);
		//printf("angley = %f\n", data->angle_data->angle_y);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		ft_modcoord(data, 2);
		//printf("anglex = %f\n", data->angle_data->angle_x);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		ft_modcoord(data, 3);
		//printf("anglex = %f\n", data->angle_data->angle_x);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
	{
		ft_modcoord(data, 4);
		//printf("zoom = %f\n", data->angle_data->zoom);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_1))
	{
		data->angle_data->angle_z += 3;
		ft_clearimage(data->image);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_2))
	{
		data->angle_data->angle_z -= 3;
		ft_clearimage(data->image);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_CONTROL))
	{
		ft_modcoord(data, 5);
		//printf("zoom = %f\n", data->angle_data->zoom);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		ft_stop_process(data, 1);
}


// void rotation_x(int y, int z, t_fdf *data, t_coor *coord)
// {
// 	int y_n = coord->y;
// 	int z_n = coord->z;

// 	int rad = data->angle_data->angle_x;
// 	y_n = (y * cos(rad)) - (z * sin(rad));
// 	z_n = (y * sin(rad)) + (z * cos(rad));
// }

// void rotation_y(int x, int z, t_fdf *data, t_coor *coord)
// {
// 	int x_n = coord->x;
// 	int z_n = coord->z;

// 	int rad = data->angle_data->angle_y;
// 	x_n = (x * cos(rad)) + (z * sin(rad));
// 	z_n = (-x * sin(rad)) + (z * cos(rad));
// }

// void rotation_z(int x, int y, t_fdf *data, t_coor *coord)
// {
// 	int x_n = coord->x;
// 	int y_n = coord->y;

// 	int rad = data->angle_data->angle_z;
// 	x_n = (x * cos(rad)) - (y * sin(rad));
// 	y_n = (x * sin(rad)) + (y * cos(rad));
// }

// t_coor	*rotation(t_fdf *data, int x, int y, int flag)
// {
// 	t_coor	*coord;

// 	coord = malloc(sizeof(t_coor));
// 	if (flag == 1)
// 		flag = x + 1;
// 	else
// 		flag = y + 1;
// 	rotation_x(y, data->pos[y][x], data, coord);
// 	rotation_y(x, coord->z, data, coord);
// 	rotation_z(coord->x, coord->y, data, coord);
// }

//int32_t	planey(int x, int y, t_fdf *data)
//{
//	float	angle_z;
//	float	angle_y;
//	float	angle_x;
//	float	zoom;
//	int		z;
//	//int		z_n;
//	int		x_n;
//	int		y_n;

//	z = data->pos[y][x];
//	zoom = data->angle_data->zoom;
//	angle_y = data->angle_data->angle_y * (M_PI / 180);
//	angle_x = data->angle_data->angle_x * (M_PI / 180);
//	angle_z = data->angle_data->angle_z * (M_PI / 180);
//	y_n = y * cos(angle_x) + z * sin(angle_x);
//	//z_n = y * -sin(angle_x) + z * cos(angle_x);
//	x_n = x * cos(angle_y) + z * sin(angle_y);
//	//z_n = x * -sin(angle_y) + z * cos(angle_y);
//	return (((x_n * sin(angle_z) + y_n * cos(angle_z))* zoom) + data->centre_y);
//}

////Conversion coordonee x vers isometrique
//int32_t	planex(int x, int y, t_fdf *data)
//{
//	float	angle_z;
//	float	angle_y;
//	float	angle_x;
//	float	zoom;
//	int		z;
//	//int		z_n;
//	int		x_n;
//	int		y_n;

//	z = data->pos[y][x];
//	zoom = data->angle_data->zoom;
//	angle_y = data->angle_data->angle_y * (M_PI / 180);
//	angle_x = data->angle_data->angle_x * (M_PI / 180);
//	angle_z = data->angle_data->angle_z * (M_PI / 180);
//	y_n = y * cos(angle_x) + z * sin(angle_x);
//	//z_n = y * -sin(angle_x) + z * cos(angle_x);
//	x_n = x * cos(angle_y) + z * sin(angle_y);
//	//z_n = x * -sin(angle_y) + z * cos(angle_y);
//	return (((x_n * cos(angle_z) - y_n * sin(angle_z))* zoom) + data->centre_y);
//}

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
//}

float normalizeAngle(float angle) {
    while (angle >= 360) {
        angle -= 360;
    }
    while (angle < 0) {
        angle += 360;
    }
    return angle;
}


int32_t planey(int x, int y, t_fdf *data)
{
	float	angle;
	float	zoom;

	angle = data->angle_data->angle_y * (M_PI / 180);
	zoom = data->angle_data->zoom;
	return (((-y * sin(angle) - data->pos[y][x] * sin(angle)) * zoom) + data->centre_y);
}

//Conversion coordonee x vers isometrique
int32_t planex(int x, int y, t_fdf *data)
{
	float angle;
	float	zoom;

	angle = data->angle_data->angle_x * (M_PI / 180);
	zoom = data->angle_data->zoom;
	return (((x + cos(angle) * data->pos[y][x] - cos(angle) * y) * zoom) + data->centre_x);
}

//destination.x = source.x + cos(angle) * source.z - cos(angle) * source.y
//destination.y = -source.y * sin(angle) - source.z * sin(angle)
