/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:46:10 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/02 21:34:09 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include <math.h>
# include <stdio.h>
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>

typedef struct s_fdf
{
    int            ymax;
    int            xmax;
    int            **pos;
	char           **content;
}					t_fdf;

int    ft_parsing(t_fdf *map, char *file_path);
int    chartoint(t_fdf *map);
void    free_int(t_fdf *map);
void ft_freesplit(char **split_result);
void	free_char(t_fdf *map);

#endif