/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:05:43 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/02 22:16:13 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_count_tab(char **tab)
{
	int c;

	c = 0;
	while (tab[c] && tab[c][0] != '\n')
	{
		c++;
	}
	return (c);
}

// get le nombre de colonne (x)

char *replace_char(char *str, char find, char new)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == find)
			str[i] = new;
		i++;
	}
	return (str);
}

void	ft_get_xmax(t_fdf *map)
{
    char **split_result;
	map->xmax = 0;
    split_result = ft_split(replace_char(map->content[0], '\n', ' '),' ');
    while(split_result[map->xmax] && split_result[map->xmax][0] != '\n')
	{
		map->xmax++;
		printf("split = %s x = %d\n", split_result[map->xmax], map->xmax);
	}
    ft_freesplit(split_result);
}

// get le nombre de ligne (y)

void	ft_get_ymax(int fd, t_fdf *map)
{
	char *line;
	map->ymax = 0;
	while((line = (get_next_line(fd))))
	{
		free(line);
		map->ymax++;
	}
}

// get fd renvoie le fd et permet d'obtenir ymax

int	get_fd(char *file, t_fdf *map)
{
	int	fd;
	int fd_count_line;

	fd = open(file, O_RDONLY);
	fd_count_line = open(file, O_RDONLY);
	if (fd < 0 || fd_count_line < 0)
	{
		perror("Fail open file");
		return (-1);
	}
	ft_get_ymax(fd_count_line, map);
	return (fd);
}

// Cette fonction pue la merde faut la refaire

int ft_checkmap(t_fdf *map, char ***content)
{
	int pos_y;

	pos_y = 0;
	while (pos_y < map->ymax)
	{
		printf("%d VS %d\n", map->xmax, ft_count_tab(content[pos_y]));
		if (map->xmax != ft_count_tab(content[pos_y]))
			return (perror("CACA"), 0);
		pos_y++;
	}
	return (1);
}

// get map stocke le fichier dans un tableau de tableau et appelle fonction xmax

void	get_map(t_fdf *map, int fd)
{
	int i;

	map->content = ft_calloc(sizeof(char *), map->ymax + 1);
	i = 0;
	while(i <= map->ymax && map->content)
		map->content[i++] = get_next_line(fd);
	ft_get_xmax(map);
}

// ATTENTION cette fonction leak mais elle fonctionne

int chartoint(t_fdf *map)
{
	char ***content;

	int y_pos = 0;
	int x_pos = 0;
	content = malloc(sizeof(char **) * map->ymax);
	while (map->content[y_pos])
	{
		content[y_pos] = ft_split(map->content[y_pos], ' ');
		y_pos++;
	}
	if (!ft_checkmap(map, content))
		return (0);
	printf("test\n");
	y_pos=0;
	map->pos = malloc(sizeof(int *) * map->ymax);
	while (y_pos < map->ymax)
		map->pos[y_pos++] = malloc(sizeof(int)*map->xmax);
	y_pos = 0;
	while (y_pos < map->ymax)
	{
		x_pos = 0;
		while (x_pos < map->xmax && content[y_pos])
		{
			map->pos[y_pos][x_pos] = ft_atoi(content[y_pos][x_pos]);
			x_pos++;
		}
		y_pos++;
	}
	return (ft_freesplit(*content), free(content), free_char(map), 1);
}

// ft_parsing renvoie 0 en cas d'erreur sinon 1

int ft_parsing(t_fdf *map, char *file_path)
{
	int fd;

	fd = get_fd(file_path, map);
	if (fd == -1)
		return (0);
	get_map(map, fd);
	printf("test\n");
	return (chartoint(map));
	printf("apres test\n");
	// if (!ft_checkmap(map))
	// 	return (perror("invalid map"), 0);
	// else
	// 	printf("good");
}