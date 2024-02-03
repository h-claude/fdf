/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:53:51 by moajili           #+#    #+#             */
/*   Updated: 2024/02/03 06:57:02 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// free la chaine de int (pos)

void	free_inttab(t_fdf *map)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	printf("size = %d\n", map->ymax-1);
	while (i <  map->ymax-1)
		free(map->pos[i++]);
	free(map->pos[i]);
	free(map->pos);
	map->pos=NULL;
}

// free le tableau content

void	free_strtab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str[i]);
	free(str);
	str=NULL;
}
