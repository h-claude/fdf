/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_point_and_lines.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:53:07 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/05 13:54:27 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/**
 * @brief Simulates a split and stops when encountering '\n' or reaches the end of the string.
 *
 * This function simulates a split operation by counting the number of substrings in the given
 * string `str` using the specified delimiter `c`. It stops when encountering '\n' or reaching
 * the end of the string. The count of substrings (points) in a line is returned.
 *
 * @param str The input string to be analyzed.
 * @param c The delimiter character for counting substrings.
 *
 * @return The number of substrings (points) in a line.
 */
int	ft_count_point(char *str, char c)
{
	int	i;
	int	nbstr;

	i = 0;
	nbstr = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if ('\n' == str[i])
			return (nbstr);
		if (str[i] != c && str[i] != '\0')
			nbstr++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (nbstr);
}

/**
 * @brief Obtains the values of `xmax` and `ymax` based on the content of the file.
 *
 * This function reads the content of the file specified by the file descriptor `fd`
 * and determines the values of `xmax` and `ymax` in the `map_data` structure. It uses
 * the `ft_count_point` function to count the number of points in each line.
 *
 * @param fd The file descriptor of the opened file.
 * @param map_data A pointer to the structure containing map data.
 */
void	ft_count_line_and_point(int fd, t_fdf *map_data)
{
	char	*temp_line;

	map_data->ymax = 0;
	temp_line = get_next_line(fd);
	if (!temp_line)
		return (perror("Fichier vide"), free(temp_line), (void)close(fd));
	map_data->xmax = ft_count_point(temp_line, ' ');
	while (temp_line)
	{
		map_data->ymax++;
		free(temp_line);
		temp_line = get_next_line(fd);
	}
	close(fd);
	free(temp_line);
}