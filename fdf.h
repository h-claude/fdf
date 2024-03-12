/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:46:10 by hclaude           #+#    #+#             */
/*   Updated: 2024/03/12 15:51:05 by hclaude          ###   ########.fr       */
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
	int			centre_y;
	int			centre_x;
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
void	free_split(char ***split_map_content, t_fdf *map_data);
void	ft_freetab(char **str);
void	ft_free_finals_maps(t_fdf *map_data);
void	ft_clearimage(mlx_image_t *image);
void	draw_map(t_fdf *map_data);
void	ft_inputs(t_fdf *map_data);
void	ft_stop_process(t_fdf *map, int flag);
void	ft_inputs(t_fdf *data);
int32_t get_the_color(char *hexa_color);
int32_t planex(int x, int y, t_fdf *data);
int32_t planey(int x, int y, t_fdf *data);

#endif