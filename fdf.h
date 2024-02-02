/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:46:10 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/02 22:57:29 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include <math.h>
# include <stdio.h>
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>

/*struct t_point
{
    int x;
    int y;
    int z;
    int color;
    struct t_point *next_h;
    struct t_point *next_v;
};

typedef struct s_point t_point;

points = calloc(500, sizeof(t_point));

points[0].x = 0;
points[0].y = 0;
points[0].z = 0;
points[0].color = 0x00FF00;
*/
typedef struct s_fdf
{
    int            ymax;
    int            xmax;
    int            **pos;
	char           **content;
}					t_fdf;

int    ft_parsing(t_fdf *map, char *file_path);
void    chartoint(t_fdf *map);
void    free_int(t_fdf *map);
void ft_freesplit(char **split_result);
void	free_char(t_fdf *map);

#endif