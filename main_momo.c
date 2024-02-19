#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int	main(int argc, char **argv)
{
	t_fdf	**map_data;
    int     y_pos = 0;

    if (argc != 2)
        return (perror("Error with arguments"), 0)
    map_data = ft_init(argv[1], &y_pos);
    printf("y_pos = %d\n", y_pos);
	if (map_data)
		printf("good !\n");

    if (map_data)
        free_alloc(map_data, y_pos);
    return (0);
}
