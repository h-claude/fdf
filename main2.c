#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <lib/MLX42/include/MLX42/MLX42.h>
#include "fdf.h"

#define WIDTH 1080
#define HEIGHT 1080

static mlx_image_t* image;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(t_fdf	**map_data)
{
	while (map_data[y])
	{
		{
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

int32_t main(int argc, char **argv)
{
	mlx_t		*mlx;
	t_fdf		**map_data;
    t_dimension *dim_map;

	if (argc != 2)
        return (perror("Error with arguments"), 0);
    dim_map = malloc(sizeof(t_dimension));
    if (!dim_map)
        return (perror("Fail alloc dim_map"), 0);
    dim_map->xmax = 0;
    dim_map->ymax = 0;
    map_data = ft_init(argv[1], dim_map);
	if (map_data)
		printf("good !\n");
    else
        return (perror("Marche pas"), 0);
	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 600, 600)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

	mlx_loop_hook(mlx, ft_randomize, map_data);
	// mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_alloc(map_data, dim_map->ymax);
    free(dim_map);
	return (EXIT_SUCCESS);
}