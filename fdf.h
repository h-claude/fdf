/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deadchicken <deadchicken@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:46:10 by hclaude           #+#    #+#             */
/*   Updated: 2024/03/08 21:00:54 by deadchicken      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "lib/turbo_libft/turbo.h"
# include <math.h>
# include <stdio.h>
# include "lib/MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>

#define WIDTH 2560
#define HEIGHT 1440

typedef struct s_angle
{
	float	angle_x;
	float	angle_y;
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
	mlx_image_t *image;
	mlx_t		*mlx;
}	t_fdf;

int	ft_init(t_fdf *map_data, char *filepath);
int	ft_count_point(char *str, char c);
int	ft_get_finals_maps(char ***split_map_content, t_fdf *map_data);
int	ft_count_line_and_point(int fd, t_fdf *map_data);
int	ft_alloc_finals_maps(t_fdf *map_data);
void	ft_free_mega_split(char ***split_map_content, t_fdf *map_data);
void	ft_freetab(char **str);
void	ft_free_finals_maps(t_fdf *map_data);
void	ft_clearimage(mlx_image_t *image);
void	drawMap(t_fdf *map_data);
void	ft_inputs(t_fdf *map_data);
int32_t get_the_color(char *hexa_color);

#endif