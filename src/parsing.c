/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:05:43 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/01 14:47:35 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_fd(char *file, t_fdf *map)
{
	int	fd;
	int fd_count_line;

	fd = open(file, O_RDONLY);
	fd_count_line = open(file, O_RDONLY);
	if (fd < 0 && fd_count_line < 0)
		return (perror("Fail open file"), -1);
	ft_count_line(fd_count_line, map);
	return (fd);
}

static void	freetab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
//faire fonction qui met ligne par ligne dans tableau de tableau

int	get_map(t_fdf *map, int fd)
{
	int i;

	map->content = malloc(sizeof(char *) * map->y);
	i = 0;
	while(i <= map->y)
	{
		map->content[i] = get_next_line(fd);
		if (!map->content[i])
			return (freetab(map->content), -1);
		i++;
	}
	map->x = ft_strlen(map->content[0]);
	return (1);
}

//check si map est valide

int ft_checkmap(t_fdf *map)
{
	// si pas bon renvoie 0
	// sinon 1
}
// fonction qui va compter le nombre Y

void	ft_count_line(int fd, t_fdf *map)
{
	map->y = 0;

	while(get_next_line(fd))
		map->y++;
}

ft_parsing(t_list *map, char *file_path)
{
	if (ft_checkmap(get_map(map, get_fd(file_path, map))));
		
}