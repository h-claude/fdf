/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_point_and_lines.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:53:07 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/15 04:58:44 by hclaude          ###   ########.fr       */
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

	void	ft_count_line_and_point(int fd, int *xmax, int *ymax)
	{
		char	*temp_line;

		temp_line = get_next_line(fd);
		if (!temp_line)
			return (perror("Fichier vide"), (void)close(fd));
		(*xmax) = ft_count_point(temp_line, ' ');
		while (temp_line)
		{
			(*ymax)++;
			free(temp_line);
			temp_line = get_next_line(fd);
			if (!temp_line)
            	break;
		}
		free(temp_line);
		close(fd);
	}
