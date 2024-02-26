#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib/MLX42/include/MLX42/MLX42.h"

#define WIDTH 512
#define HEIGHT 512

static mlx_image_t* image;
int32_t ft_planetransformery(int x, int y, int z);
int32_t ft_planetransformerx(int x, int y, int z);

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

void ft_coordy(t_fdf *map_data)
{
	int y_pos = 0;
	int x_pos = 0;

	while (y_pos < map_data->ymax)
	{
		x_pos = 0;
		while (x_pos < map_data->xmax)
		{
			map_data->coord_y[y_pos][x_pos] = ft_planetransformery(x_pos, y_pos, map_data->pos[y_pos][x_pos]);
			x_pos++;
		}
		y_pos++;
	}
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
			map_data->coord_x[y_pos][x_pos] = ft_planetransformerx(x_pos, y_pos, map_data->pos[y_pos][x_pos]);
			x_pos++;
		}
		y_pos++;
	}
}

int32_t ft_planetransformerx(int x, int y, int z)
{
	int angle = 120;
	return (x * cosf(angle) + y * cosf(angle + 2) + z * cosf(angle - 2));
}

//destination.x = source.x + cos(angle) * source.z
//destination.y = source.y + sin(angle) * source.z

int32_t ft_planetransformery(int x, int y, int z)
{
	int angle = 20;
	return (x * sinf(angle) + y * sinf(angle + 2) + z * sinf(angle - 2));
}

// void ft_hook(void* param)
// {
// 	mlx_put_pixel(image, 15, 15, 0xFFFFFFFF);
// }

void drawMap(t_fdf *map_data)
{
	int y = 0;
	int x = 0;
	printf("ON EST DANS DRAWMAP\n");
	while (y < map_data->ymax) {
		x = 0;
		while (x < map_data->xmax) {
			//printf("map_data->pos[%d][%d] = %d\n", i, j, map_data->pos[i][j]);
			//mlx_put_pixel(image, x, y, map_data->color[y][x]);
			if (map_data->coord_x[y][x] > 0 && map_data->coord_y[y][x] > 0)
			{
				printf("map_data->coord_x[%d][%d] = %d\n", y, x, map_data->coord_x[y][x]);
				mlx_put_pixel(image, map_data->coord_x[y][x], map_data->coord_y[y][x], map_data->color[y][x]);
			}
			x++;
		}
		y++;
	}
}

void loop_hook_example(void* param)
{
	// printf("DANS LOOP HOOK EXAMPLE\n");
	t_fdf *map_data = (t_fdf *)param;
	printf("map_data->xmax = %d\n", map_data->xmax);
	//for (int y = 0; y < map_data->ymax; y++) {
	//    for (int x = 0; x < map_data->xmax; x++) {
	//        printf("tdpos->coord_x[%d][%d] : %d \n", y,x,map_data->coord_x[y][x]);
	// 	    printf("tdpos->coord_y[%d][%d] : %d \n", y,x,map_data->coord_y[y][x]);
	// 	    printf("\n");
	//    }
	//}
	// for (int y = 0; y < map_data->ymax; y++) {
	//     for (int x = 0; x < map_data->xmax; x++) {
	//         printf("tdpos->coord_x[%d][%d] : %d \n", y,x,map_data->pos[y][x]);
	// 		printf("\n");
	//     }
	// }
	drawMap(map_data);
}

int	main(int argc, char **argv)
{
	mlx_t   *mlx;
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
	mlx = mlx_init(1920, 1080, "MLX42", true);
	printf("OK 1\n");
	image = mlx_new_image(mlx, 1920, 1080);
	printf("OK 2\n");
	mlx_image_to_window(mlx, image, 500, 500);
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
