/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:05:43 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/03 02:25:02 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// get le nombre de ligne (y)

void	ft_get_xmax(t_fdf *map)
{
	char	**split_result;

	map->xmax = 0;
	split_result = ft_split(map->content[0], ' ');
	while (split_result[map->xmax])
		map->xmax++;
	ft_freesplit(split_result);
}

// get le nombre de colonne (x)

void	ft_get_ymax(int fd, t_fdf *map)
{
	char	*line;

	map->ymax = 0;
	while ((line = (get_next_line(fd))))
	{
		free(line);
		map->ymax++;
	}
}

// get fd renvoie le fd et permet d'obtenir ymax

int	get_fd(char *file, t_fdf *map)
{
	int	fd;
	int	fd_count_line;

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

int	ft_checkmap(t_fdf *map)
{
}

// get map stocke le fichier dans un tableau de tableau et appelle fonction xmax

int	get_map(t_fdf *map, int fd)
{
	int	i;

	map->content = ft_calloc(sizeof(char *), map->ymax + 1);
	i = 0;
	while (i <= map->ymax && map->content)
		map->content[i++] = get_next_line(fd);
	ft_get_xmax(map);
	return (0);
}

// ATTENTION cette fonction leak mais elle fonctionne

void	chartoint(t_fdf *map)
{
	char	***content;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	content = malloc(sizeof(char **) * map->ymax);
	while (map->content[i])
	{
		content[i] = ft_split(map->content[i], ' ');
		i++;
	}
	i = 0;
	map->pos = malloc(sizeof(int *) * map->ymax);
	map->color = malloc(sizeof(char **) * map->ymax);
	while (i < map->ymax)
	{
		map->pos[i] = malloc(sizeof(int) * map->xmax);
		map->color[i] = malloc(sizeof(char *) * map->xmax);
		i++;
	}
	i = 0;
	while (i < map->ymax)
	{
		j = 0;
		while (j < map->xmax && content[i])
		{
			if (strchr(content[i][j], ','))
			{
				tmp = (ft_split(content[i][j], ','))[1];
				map->color[i][j] = ft_strdup(tmp);
				free(tmp);
			}
			else
				map->color[i][j] = NULL;
			map->pos[i][j] = ft_atoi(content[i][j]);
			j++;
		}
		i++;
	}
	ft_freesplit(*content);
	free(content);
	free_char(map);
}

// ft_parsing renvoie 0 en cas d'erreur sinon 1

int	ft_parsing(t_fdf *map, char *file_path)
{
	int	fd;

	fd = get_fd(file_path, map);
	if (fd == -1)
		return (0);
	if (get_map(map, fd) == -1)
		return (perror("invalid map"), 0);
	else
		printf("good");
	return (1);
}
