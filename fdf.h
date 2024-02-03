/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:46:10 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/03 16:07:44 by hclaude          ###   ########.fr       */
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
*/

// typedef struct s_point t_point;


typedef struct s_fdf
{
    int            ymax;
    int            xmax;
    int            **pos;
    char           ***color;
}					t_fdf;

#endif