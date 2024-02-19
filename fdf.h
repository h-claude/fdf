/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:46:10 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/15 09:48:09 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/turbo_libft/turbo.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

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
	int		x;
	int		y;
	int		z;
	int		ymax;
	int		xmax;
	int32_t	color;
	//--------//
	float	**coord_x;
	float	**coord_y;
}			t_fdf;

t_fdf		**ft_init(char *filepath, int *y);
int			ft_count_point(char *str, char c);
int			ft_get_finals_maps(char ***split_map_content, t_fdf **map_data,
				int xmax, int ymax);
int	ft_count_line_and_point(int fd, int *xmax, int *ymax);
void		ft_free_mega_split(char ***split_map_content);
void		ft_freetab(char **str);
void		free_alloc(t_fdf **allocd, int ymax);
int32_t		get_the_color(char *hexa_color);

#endif