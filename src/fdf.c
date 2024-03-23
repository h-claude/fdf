/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:48:21 by hclaude           #+#    #+#             */
/*   Updated: 2024/03/23 14:11:20 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../fdf.h"

static void	loop_hook(void *param)
{
	int		x;
	int		y;
	t_fdf	*data;

	data = (t_fdf *)param;
	x = data->angle->trans_x;
	y = data->angle->trans_y;
	ft_inputs(data);
	data->centre_y = (HEIGHT / 2) - (data->ymax * data->angle->zoom / 2) - y;
	data->centre_x = (WIDTH / 2) - (data->xmax * data->angle->zoom / 2) - x;
	draw_map(data);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		return (perror("Wrong number of arguments :/"), 0);
	data = malloc(sizeof(t_fdf));
	if (!data)
		return (perror("Fail alloc map_data :/"), 0);
	if (!ft_init(data, argv[1]))
		return (free(data), 0);
	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!data->mlx)
		return (perror("Error with mlx!"), ft_stop_process(data, 0), 0);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
		return (perror("Error with mlx image!"), ft_stop_process(data, 2), 0);
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
		return (perror("Error with mlx!"), ft_stop_process(data, 2), 0);
	mlx_loop_hook(data->mlx, loop_hook, (data));
	mlx_loop(data->mlx);
	ft_stop_process(data, 1);
	return (EXIT_SUCCESS);
}
