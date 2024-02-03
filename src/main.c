/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:29:30 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/03 00:26:38 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"


int main(int argc, char **argv)
{
    t_fdf     *map;

    map = ft_calloc(sizeof(t_fdf), 1);
    if (!map)
        return(perror("Alloc de map echoue"), 0);
    map->xmax = 0;
    map->ymax = 0;
    if (argc != 2)
        return (perror("Error: wrong number of arguments\n"), 0);
    if (!ft_parsing(map, argv[1]))
    {
        //free_int(map);
        free(map->content);
        free(map);
        exit(0);
    }
    //int h = 0;
    /*while (map->content[h])
    {
        printf("%s\n", map->content[h]);
        h++;
    }
    */
    chartoint(map);
    /*int row = 0;
    while (row < map->ymax) {
        int col = 0;
        while (col < map->xmax) {
            printf("color[%d][%d] = %s \n",row,col, map->color[row][col]);
            col++;
        }
        printf("\n");
        row++;
    }*/
    

    free_int(map);
    free(map->content);
    free(map);
}

