/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:05:43 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/03 07:36:04 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_count_tab(char **tab)
{
	int	c;

	c = 0;
	while (tab[c] && tab[c][0] != '\n')
		c++;
	return (c);
}

// get le nombre de colonne (x)

void	ft_get_xmax(t_fdf *map)
{
	char	**split_result;

	map->xmax = 0;
	int xmaxth = countstr(map->content[0], ' ');
	split_result = ft_split(map->content[0], ' ');
	while (split_result[map->xmax] && split_result[map->xmax][0] != '\n')
	{
		map->xmax++;
	//	printf("split = %s x = %d\n", split_result[map->xmax], map->xmax);
	}
	//printf("split = %d\n", map->xmax);

	free_strtab(split_result);
}

// get le nombre de ligne (y)

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
		close(fd && fd_count_line);
		perror("Error opening file");
		free(map);
		exit(10);
	}
	ft_get_ymax(fd_count_line, map);
	close(fd_count_line);
	return (fd);
}

// Cette fonction pue la merde faut la refaire

int ft_checkmap(t_fdf *map, char ***content)
{
	int	pos_y;

	pos_y = 0;
	while (pos_y < map->ymax)
	{
		//printf("%d VS %d\n", map->xmax, ft_count_tab(content[pos_y]));
		if (map->xmax != ft_count_tab(content[pos_y]))
			return (perror("CACA"), 0);
		pos_y++;
	}
	return (1);
}

// get map stocke le fichier dans un tableau de tableau et appelle fonction xmax

void	get_map(t_fdf *map, int fd)
{
	int	i;
	char *line;

	map->content = ft_calloc(sizeof(char *), map->ymax + 1);
	i = 0;
	while (i <= map->ymax && map->content)
		map->content[i++] = get_next_line(fd);
	ft_get_xmax(map);
}

// ATTENTION cette fonction leak mais elle fonctionne


int ft_malloc_int(t_fdf *map, char ****content)
{
	int i;

	i = 0;
	*content = malloc(sizeof(char **) * map->ymax);
	map->pos = malloc(sizeof(int *) * map->ymax);
	map->color = malloc(sizeof(char **) * map->ymax);
	if (!map->pos || !map->color || !*content)
			return (-1);
	while (i < map->ymax)
	{
		map->pos[i] = malloc(sizeof(int) * map->xmax);
		map->color[i] = malloc(sizeof(char *) * map->xmax);
		if (!map->pos[i] || !map->color[i])
			return (-1);
		i++;
	}
	return (0);
}

void free_memory(t_fdf *map, char ***content)
{
    int i;
	int j;
	
	i = 0;
	j = 0;
    while (i < map->ymax)
    {
        int x_pos = 0;
        while (x_pos < map->xmax && content[i][x_pos] != NULL)
            free(content[i][x_pos++]);
        free(content[i++]);
    }
    i = 0;
    while (i < map->ymax)
        free(map->pos[i++]);
    free(map->pos);    
	i = 0;
    while (i < map->ymax)
	{
		j = 0;
		while (j < map->xmax)
        	free(map->color[i][j++]);
		free(map->color[i++]);
	}
	(free(content),	free_strtab(map->content), free(map->color), free(map));
}


int	chartoint(t_fdf *map)
{
	char	***content;
	char	**tmp;
	int		y_pos;
	int		x_pos;

	y_pos = 0;
	x_pos = 0;
	ft_malloc_int(map,&content);
	while (map->content[y_pos])
	{
		content[y_pos] = ft_split(map->content[y_pos], ' ');
		y_pos++;
	}
	if (!ft_checkmap(map, content))
	 	return (free_memory(map, content),perror("MEGA MERDE"), 0);
	y_pos = 0;
	while (y_pos < map->ymax)
	{
		x_pos = 0;
		while (x_pos < map->xmax && content[y_pos])
		{
			if (strchr(content[y_pos][x_pos], ','))
			{
				tmp = ft_split(content[y_pos][x_pos], ',');
				map->color[y_pos][x_pos] = ft_strdup(tmp[1]);
				free_strtab(tmp);
			}
			else
				map->color[y_pos][x_pos] = NULL;
			map->pos[y_pos][x_pos] = ft_atoi(content[y_pos][x_pos]);
			x_pos++;
		}
		y_pos++;
	}
	return (free_memory(map, content), 1);
}


// ft_parsing renvoie 0 en cas d'erreur sinon 1

int	ft_parsing(t_fdf *map, char *file_path)
{
	int	fd;

	fd = get_fd(file_path, map);
	get_map(map, fd);
	//printf("test\n");
	return (chartoint(map));
	// if (!ft_checkmap(map))
	// 	return (perror("invalid map"), 0);
	// else
	// 	printf("good");
}
