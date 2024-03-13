/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_the_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:53:37 by hclaude           #+#    #+#             */
/*   Updated: 2024/03/13 15:16:27 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_line(int x0, int y0, int x1, int y1, t_fdf *data, int32_t color)
{
    int	dx = abs(x1 - x0);
    int	dy = abs(y1 - y0);
    int	sx = (x0 < x1) ? 1 : -1;
    int	sy = (y0 < y1) ? 1 : -1;
    int	err = dx - dy;

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

void	draw_map(t_fdf *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < data->ymax)
	{
		x = 0;
		while (x < data->xmax)
		{
			if (x == data->xmax - 1 && data->ymax > y + 1)
				draw_line(planex(x, y, data), planey(x, y, data), planex(x, y + 1, data), planey(x, y + 1, data), data, data->color[y][x]);
			else if (data->xmax > x + 1)
				draw_line(planex(x, y, data), planey(x, y, data), planex(x + 1, y, data), planey(x + 1, y, data), data, data->color[y][x]);
			if (y == data->ymax - 1 && data->xmax > x + 1)
				draw_line(planex(x, y, data), planey(x, y, data), planex(x + 1, y, data), planey(x + 1, y, data), data, data->color[y][x]);
			else if (data->ymax > y + 1)
				draw_line(planex(x, y, data), planey(x, y, data), planex(x, y + 1, data), planey(x, y + 1, data), data, data->color[y][x]);
			x++;
		}
		y++;
	}
}
