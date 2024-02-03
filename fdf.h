/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:46:10 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/03 02:28:22 by moajili          ###   ########.fr       */
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
points[0].color = 0;

points[1].x = 1;
points[1].y = 0;
points[1].z = 0;
points[1].color = 0;

points[2].x = 2;
points[2].y = 0;
points[2].z = 1;
points[2].color = 0;

points[250000].x = 
points[250000].y = 
points[250000].z = 
points[250000].color = 
points[0].color = 0x00FF00;
*/
typedef struct s_fdf
{
    int            ymax;
    int            xmax;
    int            **pos;    
    char            ***color;
	char           **content;
}					t_fdf;

int    ft_parsing(t_fdf *map, char *file_path);
int    chartoint(t_fdf *map);
void    free_int(t_fdf *map);
void ft_freesplit(char **split_result);
void	free_char(t_fdf *map);

#endif