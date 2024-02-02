/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:29:30 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/02 14:20:55 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"


int main(int argc, char **argv)
{
    t_fdf     *map;

    map = ft_calloc(sizeof(t_fdf), 1);
    if (!map)
        return(perror("NOOOOOOOOOOON"), 0);
    map->xmax = 0;
    map->ymax = 0;
    if (argc != 2)
        return (perror("Error: wrong number of arguments\n"), 0);
    ft_parsing(map, argv[1]);
    final(map);

     int row = 0;




   
    while (row < map->ymax) {
        int col = 0;
        while (col < map->xmax) {
            printf("pos[%d][%d] = %d \n",row,col, map->pos[row][col]);
            col++;
        }
        printf("\n");
        row++;
    }



    freebox(map);
    free(map->content);
    free(map);
}