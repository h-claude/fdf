/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:12:22 by hclaude           #+#    #+#             */
/*   Updated: 2024/03/08 18:38:14 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// faire une fonction qui clear l'image
void	ft_clearimage(mlx_image_t *image)
{
	int y_pos;
	int x_pos;

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
// faire une fonction qui modifie les valeurs apres inputs

void	ft_modcoord(t_fdf *map_data, int flag)
{
	if (flag == 0)
		map_data->angle_data->angle_y += 0.05;
	if (flag == 1)
		map_data->angle_data->angle_y -= 0.05;
	if (flag == 2)
		map_data->angle_data->angle_x += 0.05;
	if (flag == 3)
		map_data->angle_data->angle_x -= 0.05;
	if (flag == 4)
		map_data->angle_data->zoom += 0.05;
	if (flag == 5 && map_data->angle_data->zoom > 0.10)
		map_data->angle_data->zoom -= 0.05;
	ft_clearimage(map_data->image);
}

void	ft_stop_process(t_fdf *map)
{
	mlx_terminate(map->mlx);
	ft_free_finals_maps(map);
	free(map);
	exit(1);
}

// faire une fonction qui prend les inputs du clavier

void	ft_inputs(t_fdf *data)
{
	//printf("Dans ft_inputs\n");
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		ft_modcoord(data, 0); // rotation vers l'avant
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		ft_modcoord(data, 1); // rotation vers l'arriere
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		ft_modcoord(data, 2); // rotation vers la droite
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		ft_modcoord(data, 3); // rotation vers la gauche
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
		ft_modcoord(data, 4); // zoom avant
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_CONTROL))
		ft_modcoord(data, 5); // zoom arriere
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		ft_stop_process(data);
}

// faire une fonction bresenham

//Conversion coordonee y vers isometrique
int32_t ft_planetransformery(int x, int y, t_fdf *data)
{
	return ((x * sin(data->angle_data->angle_y) + y * cos(data->angle_data->angle_y + 2) + data->pos[y][x] * cos(data->angle_data->angle_y - 2))* data->angle_data->zoom);
}

//Conversion coordonee x vers isometrique
int32_t ft_planetransformerx(int x, int y, t_fdf *data)
{
	return ((x * sin(data->angle_data->angle_x) + y * sin(data->angle_data->angle_x + 2) + data->pos[y][x] * sin(data->angle_data->angle_x - 2))* data->angle_data->zoom);
}

void draw_line(int x0, int y0, int x1, int y1, t_fdf *data, int32_t color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while(1)
    {
		if (x0 >= 0 && x0 < WIDTH && y0 >= 0 && y0 < HEIGHT)
        	mlx_put_pixel(data->image, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void drawMap(t_fdf *map_data)
{
	int centre_x = (WIDTH / 2) - (map_data->xmax * map_data->angle_data->zoom / 2);
	int centre_y = (HEIGHT / 2) - (map_data->ymax * map_data->angle_data->zoom / 2);
	int y = 0;
	int x = 0;
	while (y < map_data->ymax)
	{
		x = 0;
		while (x < map_data->xmax)
		{
			if (x == map_data->xmax - 1 && map_data->ymax > y + 1)
				draw_line(ft_planetransformerx(x,y,map_data) + centre_x, ft_planetransformery(x,y,map_data) + centre_y, ft_planetransformerx(x,y+1,map_data) + centre_x, ft_planetransformery(x,y+1,map_data) + centre_y, map_data, map_data->color[y][x]);
			else if (map_data->xmax > x + 1)
				draw_line(ft_planetransformerx(x,y,map_data) + centre_x, ft_planetransformery(x,y,map_data) + centre_y, ft_planetransformerx(x+1,y,map_data) + centre_x, ft_planetransformery(x+1,y,map_data) + centre_y, map_data, map_data->color[y][x]); // Draw horizontal line
			if (y == map_data->ymax - 1 && map_data->xmax > x + 1)
				draw_line(ft_planetransformerx(x,y,map_data) + centre_x, ft_planetransformery(x,y,map_data) + centre_y, ft_planetransformerx(x+1,y,map_data) + centre_x, ft_planetransformery(x+1,y,map_data) + centre_y, map_data, map_data->color[y][x]);
			else if (map_data->ymax > y + 1)
				draw_line(ft_planetransformerx(x,y,map_data) + centre_x, ft_planetransformery(x,y,map_data) + centre_y, ft_planetransformerx(x,y+1,map_data) + centre_x, ft_planetransformery(x,y+1,map_data) + centre_y, map_data, map_data->color[y][x]); // Draw vertical line
			x++;
		}
		y++;
	}
}
