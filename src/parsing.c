/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:05:43 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/01 18:05:06 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// fonction qui va compter le nombre Y

void	ft_count_y(int fd, t_fdf *map)
{
	printf("dans ft count y\n");
	map->y = 0;

	while(get_next_line(fd))
		map->y++;
}

int	get_fd(char *file, t_fdf *map)
{
	int	fd;
	int fd_count_line;

	printf("dans get fd\n");
	fd = open(file, O_RDONLY);
	fd_count_line = open(file, O_RDONLY);
	if (fd < 0 && fd_count_line < 0)
		return (perror("Fail open file"), -1);
	ft_count_y(fd_count_line, map);
	return (fd);
}

static void	freetab(t_fdf *map)
{
	int	i;

	i = 0;
	printf("dans freetab\n");
	while(map->content[i++])
		printf("tab = %s et i = %d\n", map->content[i], i);
	i = 0;
	while (map->content[i])
	{
		printf("contenu = %s et i = %d\n", map->content[i], i);
		free(map->content[i]);
		i++;
	}
	free(map->content[i]);
}
//check si map est valide

int ft_checkmap(t_fdf *map)
{
	size_t len;
	size_t temp_y;
	printf("dans check map\n");
	temp_y = map->y - 1;
	len = ft_strlen(map->content[temp_y]);
	printf("len = %zu et y = %zu\n", len, map->y);
	while(len == ft_strlen(map->content[temp_y]) && temp_y > 0)
	{
		printf("len = %zu et ft_strlen = %zu\n", len, ft_strlen(map->content[temp_y]));
		temp_y--;
	}
	printf("len = %zu et ft_strlen = %zu\n le contenu est = | %s |\n et y = %zu\n", len, ft_strlen(map->content[temp_y]), map->content[temp_y], temp_y);
	if (len != ft_strlen(map->content[temp_y]))
		return (-1);
	return (1);
}

//faire fonction qui met ligne par ligne dans tableau de tableau

int	get_map(t_fdf *map, int fd)
{
	size_t i;
	printf("dans get map\n");
	map->content = ft_calloc(sizeof(char *), map->y);
	i = 0;
	while(i <= map->y && map->content)
	{
		map->content[i] = get_next_line(fd);
		i++;
	}
	map->x = ft_strlen(map->content[0]);
	i = 0;
	while(map->content[i])
	{
		printf("contenu = %s\n", map->content[i]);
		i++;
	}
	return (ft_checkmap(map));
}


void ft_parsing(t_fdf *map, char *file_path)
{
	printf("on est la\n");
	int fd;

	fd = get_fd(file_path, map);
	if (get_map(map, fd) == -1)
		printf("pas good");
	else
		printf("good");
	return;
}