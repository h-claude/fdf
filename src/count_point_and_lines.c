/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_point_and_lines.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:53:07 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/21 14:24:00 by hclaude          ###   ########.fr       */
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

int	ft_count_line_and_point(int fd, int *xmax, int *ymax)
{
		char	*temp_line;
		// int i = 35;

		temp_line = get_next_line(fd);
		if (!temp_line)
			return (perror("Fichier vide"), (void)close(fd), 0);
		(*xmax) = ft_count_point(temp_line, ' ');
		if (!*xmax)
			return (free(temp_line), 0);
		while (temp_line)
		{
			(*ymax)++;
			free(temp_line);
			temp_line = get_next_line(fd);
			// if (!i)
			// 	return (free(temp_line), (void)close(fd), 1); // Le probleme etait ici
			// i--;
		}
		if (!*ymax)
			return (free(temp_line), 0);
		return (free(temp_line), (void)close(fd), 1);
}
