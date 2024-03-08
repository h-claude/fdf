/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_point_and_lines.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:53:07 by hclaude           #+#    #+#             */
/*   Updated: 2024/03/08 18:44:42 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_count_point(char *str, char c)
{
	int	i;
	int	nbstr;

	i = 0;
	nbstr = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if ('\n' == str[i])
			return (nbstr);
		if (str[i] != c && str[i])
			nbstr++;
		while (str[i] != c && str[i])
			i++;
	}
	return (nbstr);
}

/**
 * @brief Obtains the values of `xmax` and `ymax`
 * based on the content of the file.
 *
 * This function reads the content of the file
 * specified by the file descriptor `fd`
 * and determines the values of `xmax` and `ymax`
 * in the `map_data` structure. It uses
 * the `ft_count_point` function to count the
 * number of points in each line.
 * It returns 0 if the function has a problem and 1 else
 *
 * @param fd The file descriptor of the opened file.
 * @param map_data A pointer to the structure containing map data.
 */
int	ft_count_line_and_point(int fd, t_fdf *map_data)
{
		char	*temp_line;
		// int i = 35;

	map_data->ymax = 0;
	temp_line = get_next_line(fd);
	if (!temp_line)
		return (perror("Empty file"), (void)close(fd), 0);
	map_data->xmax = ft_count_point(temp_line, ' ');
	if (!map_data->xmax)
		return (free(temp_line), 0);
	while (temp_line)
	{
		map_data->ymax++;
		free(temp_line);
		temp_line = get_next_line(fd);
	}
	if (!map_data->ymax)
			return (free(temp_line), 0);
	return ((void)close(fd), free(temp_line), 1);
}
