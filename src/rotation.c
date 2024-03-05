/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:12:22 by hclaude           #+#    #+#             */
/*   Updated: 2024/03/05 17:18:16 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// faire une fonction qui clear l'image
void	ft_clearimage(mlx_image_t *image)
{
	int y_pos;
	int x_pos;

	y_pos = 0;
	while (y_pos <= HEIGHT)
	{
		x_pos = 0;
		while (x_pos <= WIDTH)
		{
			mlx_put_pixel(image, x_pos, y_pos, 0xff00FF00);
			x_pos++;
		}
		y_pos++;
	}
}
// faire une fonction qui modifie les valeurs apres inputs

void	ft_modcoord(t_fdf *map_data, int flag, mlx_image_t *image)
{
	if (flag == 0)
		map_data->angle_data->angle_y += 5;
	if (flag == 1)
		map_data->angle_data->angle_y -= 5;
	if (flag == 2)
		map_data->angle_data->angle_x += 5;
	if (flag == 3)
		map_data->angle_data->angle_x -= 5;
	if (flag == 4)
		map_data->angle_data->zoom += 0.5;
	if (flag == 5 && map_data->angle_data->zoom > 0.10)
		map_data->angle_data->zoom -= 0.5;
	ft_clearimage(image);
}

void	ft_stop_process(mlx_t *mlx, t_fdf *map)
{
	mlx_terminate(mlx);
	ft_free_finals_maps(map);
	free(map);
	exit(1);
}

// faire une fonction qui prend les inputs du clavier

void	ft_inputs(t_fdf *map_data, mlx_t *mlx, mlx_image_t *image)
{
	//printf("Dans ft_inputs\n");
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		printf("Z angley = %d\n", map_data->angle_data->angle_y);
		ft_modcoord(map_data, 0, image); // rotation vers l'avant
	}
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		printf("S angley = %d\n", map_data->angle_data->angle_y);
		ft_modcoord(map_data, 1, image); // rotation vers l'arriere
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		printf("D anglex = %d\n", map_data->angle_data->angle_x);
		ft_modcoord(map_data, 2, image); // rotation vers la droite
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		printf("A anglex = %d\n", map_data->angle_data->angle_x);
		ft_modcoord(map_data, 3, image); // rotation vers la gauche
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT))
	{
		printf("Left shift zoom = %f\n", map_data->angle_data->zoom);
		ft_modcoord(map_data, 4, image); // zoom avant
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_CONTROL))
	{
		printf("Left control zoom = %f\n", map_data->angle_data->zoom);
		ft_modcoord(map_data, 5, image); // zoom arriere
	}
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		ft_stop_process(mlx, map_data);

}

void ft_alloccoord(t_fdf *tdpos, int ymax, int xmax)
{
	int y_pos = 0;

	tdpos->coord_x = ft_calloc(sizeof(int32_t *), ymax);
	while (y_pos <= ymax)
		tdpos->coord_x[y_pos++] = ft_calloc(sizeof(int32_t), xmax);
	y_pos = 0;
	tdpos->coord_y = ft_calloc(sizeof(int32_t *), ymax);
	while (y_pos <= ymax)
		tdpos->coord_y[y_pos++] = ft_calloc(sizeof(int32_t), xmax);
}

// faire une fonction bresenham

//Conversion coordonee y vers isometrique
int32_t ft_planetransformery(int x, int y, t_fdf *data)
{
	return ((x * sinf(data->angle_data->angle_y) + y * sinf(data->angle_data->angle_y + 2) + data->pos[y][x] * sinf(data->angle_data->angle_y - 2)) * data->angle_data->zoom);
}

void ft_coordy(t_fdf *map_data)
{
	int y_pos = 0;
	int x_pos = 0;

	while (y_pos < map_data->ymax)
	{
		x_pos = 0;
		while (x_pos < map_data->xmax)
		{
			map_data->coord_y[y_pos][x_pos] = ft_planetransformery(x_pos, y_pos, map_data);
			x_pos++;
		}
		y_pos++;
	}
}

//Conversion coordonee x vers isometrique
int32_t ft_planetransformerx(int x, int y, t_fdf *data)
{
	return ((x * cosf(data->angle_data->angle_x) + y * cosf(data->angle_data->angle_x + 2) + data->pos[y][x] * cosf(data->angle_data->angle_x - 2)) * data->angle_data->zoom);
}

void ft_coordx(t_fdf *map_data)
{
	int y_pos = 0;
	int x_pos = 0;

	while (y_pos < map_data->ymax)
	{
		x_pos = 0;
		while (x_pos < map_data->xmax)
		{
			map_data->coord_x[y_pos][x_pos] = ft_planetransformerx(x_pos, y_pos, map_data);
			x_pos++;
		}
		y_pos++;
	}
}

//destination.x = source.x + cos(angle) * source.z
//destination.y = source.y + sin(angle) * source.z

// faire une fonction pour afficher les pixels
void drawMap(t_fdf *map_data, mlx_image_t *image)
{
	int y = 0;
	int x = 0;
	while (y < map_data->ymax) {
		x = 0;
		while (x < map_data->xmax) {
			//printf("map_data->pos[%d][%d] = %d\n", i, j, map_data->pos[i][j]);
			//mlx_put_pixel(image, x, y, map_data->color[y][x]);
			if ((ft_planetransformerx(x, y, map_data) >= 0 && ft_planetransformerx(x, y ,map_data) < WIDTH) && (ft_planetransformery(x,y, map_data) >= 0 && ft_planetransformery(x, y, map_data) < HEIGHT))
			{
				//printf("map_data->coord_x[%d][%d]\n", y, x);
				mlx_put_pixel(image, ft_planetransformerx(x, y, map_data), ft_planetransformery(x,y, map_data), map_data->color[y][x]);
			}
			x++;
		}
		y++;
	}
}