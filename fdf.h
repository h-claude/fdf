/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:46:10 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/05 14:01:22 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "turbo_libft/turbo.h"
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
*/

// typedef struct s_point t_point;


typedef struct s_fdf
{
    int            ymax;
    int            xmax;
    int            **pos;
    char           ***color;
}					t_fdf;

int	ft_init(t_fdf *map_data, char *filepath);
int	ft_count_point(char *str, char c);
int	ft_get_finals_maps(char ***split_map_content, t_fdf *map_data);
void	ft_count_line_and_point(int fd, t_fdf *map_data);
void	ft_free_mega_split(char ***split_map_content, t_fdf *map_data);
void	ft_freetab(char **str);
void	ft_free_finals_maps(t_fdf *map_data);

#endif