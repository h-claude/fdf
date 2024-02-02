/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:05:43 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/02 15:39:07 by moajili          ###   ########.fr       */
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
void ft_xmax(t_fdf *fdf)
{
    char **split_result;
	
	fdf->xmax = 0;
    split_result = ft_split(fdf->content[0],' ');
    while(split_result[fdf->xmax])
		fdf->xmax++;
    ft_freesplit(split_result);
}

static void	free_char(t_fdf *map)
{
	int	i;

	i = 0;
	while (map->content[i])
		free(map->content[i++]);
	free(map->content[i]);
}

void	ft_count_y(int fd, t_fdf *map)
{
	char *line;

	map->ymax = 0;
	while((line = (get_next_line(fd))))
	{
		free(line);
		map->ymax++;
	}
}

int	get_fd(char *file, t_fdf *map)
{
	int	fd;
	int fd_count_line;

	fd = open(file, O_RDONLY);
	fd_count_line = open(file, O_RDONLY);
	if (fd < 0 && fd_count_line < 0)
		return (perror("Fail open file"), -1);
	ft_count_y(fd_count_line, map);
	return (fd);
}

int ft_checkmap(t_fdf *map)
{
	size_t len;
	size_t temp_y;
	temp_y = map->ymax - 1;
	len = ft_strlen(map->content[temp_y]);
	while(len == ft_strlen(map->content[temp_y]) && temp_y > 0)
		temp_y--;
	if (len != ft_strlen(map->content[temp_y]))
		return (-1);
	return (1);
}

int	get_map(t_fdf *map, int fd)
{
	int i;
	map->content = ft_calloc(sizeof(char *), map->ymax + 1);
	i = 0;
	while(i <= map->ymax && map->content)
		map->content[i++] = get_next_line(fd);
	ft_xmax(map);
	return (0);
}

void ft_parsing(t_fdf *map, char *file_path)
{
	int fd;

	fd = get_fd(file_path, map);
	if (get_map(map, fd) == -1)
		printf("pas good");
	else
		printf("good");
	return;
}

void chartoint(t_fdf *fdf)
{
	char ***content;
	int i = 0;
	int j = 0;
	content = malloc(sizeof(char **) * fdf->ymax);
	while (fdf->content[i])
	{
		content[i] = ft_split(fdf->content[i], ' ');
		i++;
	}
	i=0;
	fdf->pos = malloc(sizeof(int *) * fdf->ymax);
	while (i < fdf->ymax)
		fdf->pos[i++] = malloc(sizeof(int)*fdf->xmax);
	i = 0;
	while (i < fdf->ymax)
	{
		j = 0;
		while (j < fdf->xmax && content[i])
		{
			fdf->pos[i][j] = ft_atoi(content[i][j]);
			j++;
		}
		i++;
	}
	ft_freesplit(*content);
	free(content);
	free_char(fdf);
}
