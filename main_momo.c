#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void **free_alloc(t_fdf **allocd, int ymax)
{
	while (ymax >= 0)
		free(allocd[ymax--]);
	free(allocd);
	return (0);
}


int	main(int argc, char **argv)
{
	t_fdf	**map_data;
    int y_pos = 0;

    (void)argc;
    map_data = ft_init(argv[1], &y_pos);
    printf("y_pos = %d\n", y_pos);
	if (map_data)
		printf("good !\n");
    
    if (map_data)
        free_alloc(map_data, y_pos);
    return (0);
}
