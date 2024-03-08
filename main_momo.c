#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib/MLX42/include/MLX42/MLX42.h"

void loop_hook(void* param)
{
	t_fdf *map_data = (t_fdf *)param;
	ft_inputs(map_data);
	drawMap(map_data);
}

int	main(int argc, char **argv)
{
	t_fdf	*map_data;

	if (argc != 2)
		return (perror("Wrong number of arguments"), 0);
	map_data = malloc(sizeof(t_fdf));
	if (!map_data)
		return (perror("Fail alloc map_data :/"), 0);
	map_data->angle_data = malloc(sizeof(t_angle));
	if (!map_data->angle_data)
		return (perror("fail alloc angle_data"), 0);
	if (!ft_init(map_data, argv[1]))
		return(perror("Fail!\n"), 0);
	map_data->angle_data->angle_x = 90;
	map_data->angle_data->angle_y = 90;
	map_data->angle_data->angle_z = 0;
	map_data->angle_data->zoom = 1;
	map_data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	map_data->image = mlx_new_image(map_data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(map_data->mlx, map_data->image, 0, 0);
	mlx_loop_hook(map_data->mlx, loop_hook, (map_data));
	mlx_loop(map_data->mlx);
	mlx_terminate(map_data->mlx);
	ft_free_finals_maps(map_data);
	free(map_data);
	return (EXIT_SUCCESS);
}
