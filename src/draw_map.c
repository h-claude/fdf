/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:53:37 by hclaude           #+#    #+#             */
/*   Updated: 2024/03/18 18:32:22 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_bres	init_bres(int x1, int y1, t_fdf *data)
{
	t_bres	bres;

	bres.x0 = data->coor->x;
	bres.y0 = data->coor->y;
	bres.dx = abs(x1 - bres.x0);
	bres.dy = abs(y1 - bres.y0);
	if (bres.x0 < x1)
		bres.sx = 1;
	else
		bres.sx = -1;
	if (bres.y0 < y1)
		bres.sy = 1;
	else
		bres.sy = -1;
	bres.err = bres.dx - bres.dy;
	return (bres);
}

static void	draw_line(int x1, int y1, t_fdf *data)
{
	t_bres	bres;

	bres = init_bres(x1, y1, data);
	while (1)
	{
		if (bres.x0 >= 0 && bres.x0 < WIDTH && bres.y0 >= 0 && bres.y0 < HEIGHT)
			mlx_put_pixel(data->image, bres.x0, bres.y0, data->coor->color);
		if (bres.x0 == x1 && bres.y0 == y1)
			break ;
		bres.e2 = 2 * bres.err;
		if (bres.e2 > -bres.dy)
		{
			bres.err -= bres.dy;
			bres.x0 += bres.sx;
		}
		if (bres.e2 < bres.dx)
		{
			bres.err += bres.dx;
			bres.y0 += bres.sy;
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
			data->coor->x = planex(x, y, data);
			data->coor->y = planey(x, y, data);
			data->coor->color = data->color[y][x];
			if (x == data->xmax - 1 && data->ymax > y + 1)
				draw_line(planex(x, y + 1, data), planey(x, y + 1, data), data);
			else if (data->xmax > x + 1)
				draw_line(planex(x + 1, y, data), planey(x + 1, y, data), data);
			if (y == data->ymax - 1 && data->xmax > x + 1)
				draw_line(planex(x + 1, y, data), planey(x + 1, y, data), data);
			else if (data->ymax > y + 1)
				draw_line(planex(x, y + 1, data), planey(x, y + 1, data), data);
			x++;
		}
		y++;
	}
}
