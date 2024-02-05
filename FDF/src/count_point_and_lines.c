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


// count point fait une simulation de split et s'arrette quand \n || Renvoie le nombre de point d'une ligne

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

// Obtient xmax et ymax

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