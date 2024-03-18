/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:48:21 by hclaude           #+#    #+#             */
/*   Updated: 2024/03/18 18:59:08 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../fdf.h"

//#define CALLS 10000

//void *super_malloc(size_t len)
//{
//    static int call = 0;

//	printf("super_malloc called %d times, len = %zu\n", call, len);
//    if (call++ < CALLS)
//        return (malloc(len));
//    else
//        return (NULL);
//}

//void *super_calloc(size_t len, size_t len1)
//{
//    static int call1 = 0;

//	printf("super_calloc called %d times, len = %zu\n", call1, len);
//    if (call1++ < CALLS)
//        return (calloc(len, len1));
//    else
//        return (NULL);
//}

void	loop_hook(void *param)
{
	t_fdf	*data;

	data = (t_fdf *)param;
	ft_inputs(data);
	data->centre_y = (HEIGHT / 2) - (data->ymax * data->angle->zoom / 2);
	data->centre_x = (WIDTH / 2) - (data->xmax * data->angle->zoom / 2);
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
		return (perror("Error with mlx image!"), ft_stop_process(data, 0), 0);
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
		return (perror("Error with mlx!"), ft_stop_process(data, 0), 0);
	mlx_loop_hook(data->mlx, loop_hook, (data));
	mlx_loop(data->mlx);
	ft_stop_process(data, 0);
	return (EXIT_SUCCESS);
}
