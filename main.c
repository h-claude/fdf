#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib/MLX42/include/MLX42/MLX42.h"

void loop_hook(void* param)
{
	t_fdf *data = (t_fdf *)param;
	ft_inputs(data);
	data->centre_y = (HEIGHT / 2) - (data->ymax * data->angle_data->zoom / 2);
	data->centre_x = (WIDTH / 2) - (data->xmax * data->angle_data->zoom / 2);
	draw_map(data);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		return (perror("Wrong number of arguments"), EXIT_FAILURE);
	data = malloc(sizeof(t_fdf));
	if (!data)
		return (perror("Fail alloc map_data :/"), EXIT_FAILURE);
	if (!ft_init(data, argv[1]))
		return(perror("Fail!"), free(data), EXIT_FAILURE);
	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!data->mlx)
		return(perror("Error with mlx!"), ft_stop_process(data, 0), EXIT_FAILURE);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
		return(perror("Error with mlx image!"), ft_stop_process(data, 0), EXIT_FAILURE);
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
		return(perror("Error with mlx!"), ft_stop_process(data, 0), EXIT_FAILURE);
	mlx_loop_hook(data->mlx, loop_hook, (data));
	mlx_loop(data->mlx);
	ft_stop_process(data, 1);
	return (EXIT_SUCCESS);
}
