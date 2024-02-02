/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:53:51 by moajili           #+#    #+#             */
/*   Updated: 2024/02/02 15:56:25 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_int(t_fdf *map)
{
	int	i;

	i = 0;
	while (i < map->ymax)
		free(map->pos[i++]);
	free(map->pos);
}

void ft_freesplit(char **split_result)
{
    int i;

    i = 0;
    while (split_result[i])
        free(split_result[i++]);
    free(split_result);
    split_result = NULL;
}

void	free_char(t_fdf *map)
{
	int	i;

	i = 0;
	while (map->content[i])
		free(map->content[i++]);
	free(map->content[i]);
}
