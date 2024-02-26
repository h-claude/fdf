/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:46:10 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/26 17:12:26 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "lib/turbo_libft/turbo.h"
# include <math.h>
# include <stdio.h>
# include "lib/MLX42/include/MLX42/MLX42.h"
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

typedef struct s_angle
{
	int	angle_x;
	int	angle_y;
	int angle_z;
	float	zoom;
}	t_angle;

typedef struct s_fdf
{
	int			ymax;
	int			xmax;
	int			**pos;
	int32_t		**color;
	int32_t		**coord_x;
	int32_t		**coord_y;
	t_angle		*angle_data;
}					t_fdf;


int	ft_init(t_fdf *map_data, char *filepath);
int	ft_count_point(char *str, char c);
int	ft_get_finals_maps(char ***split_map_content, t_fdf *map_data);
int	ft_count_line_and_point(int fd, t_fdf *map_data);
void	ft_free_mega_split(char ***split_map_content, t_fdf *map_data);
void	ft_freetab(char **str);
void	ft_free_finals_maps(t_fdf *map_data);
int32_t get_the_color(char *hexa_color);
int	ft_alloc_finals_maps(t_fdf *map_data);

#endif