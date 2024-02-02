/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:53:51 by moajili           #+#    #+#             */
/*   Updated: 2024/02/02 16:15:52 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// free la chaine de int (pos)

void	free_int(t_fdf *map)
{
	int	i;

	i = 0;
	while (i < map->ymax)
		free(map->pos[i++]);
	free(map->pos);
}

// free la chaine faite par split

void ft_freesplit(char **split_result)
{
    int i;

    i = 0;
    while (split_result[i])
        free(split_result[i++]);
    free(split_result);
    split_result = NULL;
}

// free le tableau content

void	free_char(t_fdf *map)
{
	int	i;

	i = 0;
	while (map->content[i])
		free(map->content[i++]);
	free(map->content[i]);
}
