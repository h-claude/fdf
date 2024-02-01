/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:29:30 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/01 17:11:24 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"


int main(int argc, char **argv)
{
    t_fdf     *map;

    map = ft_calloc(sizeof(t_fdf), 1);
    if (!map)
        return(perror("NOOOOOOOOOOON"), 0);
    map->x = 0;
    map->y = 0;
    if (argc != 2)
        return (perror("Error: wrong number of arguments\n"), 0);
    ft_parsing(map, argv[1]);
}