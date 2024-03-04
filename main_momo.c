#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib/MLX42/include/MLX42/MLX42.h"

static	mlx_image_t* image;
static	mlx_t   *mlx;


void loop_hook_example(void* param)
{
	t_fdf *map_data = (t_fdf *)param;
	ft_inputs(map_data, mlx);
	drawMap(map_data, image);
}

int	main(int argc, char **argv)
{
	t_fdf	*map_data;
	// t_3dpos *tdpos;

	if (argc != 2)
		return (perror("Wrong number of arguments"), 0);
	map_data = malloc(sizeof(t_fdf));
	if (!map_data)
		return (perror("Fail alloc map_data :/"), 0);
	map_data->angle_data = malloc(sizeof(t_angle));
	if (!map_data->angle_data)
		return (perror("fail alloc angle_data"), 0);
	if (ft_init(map_data, argv[1]))
		printf("good !\n");
	else
		return(perror("Fail!\n"), 0);
	//ft_free_finals_maps(map_data);
	//free(map_data->angle_data);
	//free(map_data);
	//return (EXIT_SUCCESS);
	// ------ //
	ft_alloccoord(map_data, map_data->ymax, map_data->xmax);
	ft_coordy(map_data);
	ft_coordx(map_data);
	// for (int y = 0; y < map_data->ymax; y++) {
	//     for (int x = 0; x < map_data->xmax; x++) {
	//         printf("tdpos->coord_x[%d][%d] : %f \n", y,x,map_data->coord_x[y][x]);
	// 		printf("tdpos->coord_y[%d][%d] : %f \n", y,x,map_data->coord_y[y][x]);
	// 		printf("\n");
	//     }
	// }
	// tdpos->coord_x[0][1]=ft_planetransformerx(0,1,map_data->pos[0][1]);
	// tdpos->coord_y[0][1]=ft_planetransformery(0,1,map_data->pos[0][1]);
	// tdpos->coord_x[0][2]=ft_planetransformerx(0,2,map_data->pos[0][2]);
	// tdpos->coord_y[0][2]=ft_planetransformery(0,2,map_data->pos[0][2]);
	// for (int y = 0; y < map_data->ymax; y++) {
	//     for (int x = 0; x < map_data->xmax; x++) {
	//        printf("map_data->pos[%d][%d] : %d \n", y,x,map_data->pos[y][x]);
	// 	printf("\n");
	//    }
	// }
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	printf("OK 1\n");
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	printf("OK 2\n");
	mlx_image_to_window(mlx, image, 100, 100);
	printf("OK 3\n");
	mlx_loop_hook(mlx, loop_hook_example, (map_data));
	printf("OK 4\n");
	mlx_loop(mlx);
	printf("OK 5\n");
	mlx_terminate(mlx);
	ft_free_finals_maps(map_data);
	free(map_data);
	return (EXIT_SUCCESS);
}
