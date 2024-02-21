#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int	main(int argc, char **argv)
{
	t_fdf	**map_data;
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
    free_alloc(map_data, dim_map->ymax);
    free(dim_map);
    return (0);
}
