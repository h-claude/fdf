/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:27:30 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/14 16:07:32 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Main function to demonstrate map initialization and processing.
 *
 * This function serves as the main entry point for the program. It allocates
 * memory for the map data, initializes the map using `ft_init`, and prints a
 * success message if the initialization is successful. It also frees the memory
 * allocated for the map data.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of strings containing the command-line arguments.
 *
 * @return 0 on successful execution.
 */

int	main(int argc, char **argv)
{
	t_fdf	*map_data;

	if (argc != 2)
		return(perror("Mauvais nombre d'arguments"), 0);
	map_data = malloc(sizeof(t_fdf));
	if (!map_data)
		return (perror("Allocation de map_data echouee"), 0);
	map_data->xmax = 0;
	map_data->ymax = 0;
	if (ft_init(map_data, argv[1]))
		printf("good !\n");
	else
		return (perror("Parsing fail"), free(map_data), 0);
	// int y = 0;
	// int x = 0;
	// while(y < map_data->ymax)
	// {
	// 	x = 0;
	// 	while(x < map_data->xmax)
	// 	{
	// 		printf("(y = %d, x = %d) = %d\n", y, x, map_data->pos[y][x]);
	// 		x++;
	// 	}
	// 	printf("\n");
	// 	y++;
	// }
	ft_free_finals_maps(map_data);
	free(map_data);
}