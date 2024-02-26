/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:12:22 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/26 17:04:40 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// faire une fonction qui clear l'image

// faire une fonction qui modifie les valeurs apres inputs

void	ft_modcoord(t_fdf *map_data, int flag)
{
	if (flag == 0)
		map_data->angle_data->angle_y += 6;
	if (flag == 1)
		map_data->angle_data->angle_y -= 6;
	if (flag == 2)
		map_data->angle_data->angle_x += 6;
	if (flag == 3)
		map_data->angle_data->angle_x -= 6;
	if (flag == 4)
		map_data->angle_data->zoom += 0,5;
	if (flag == 5 && map_data->angle_data->zoom >= 0,10)
		map_data->angle_data->zoom -= 0,5;
}

// faire une fonction qui prend les inputs du clavier

void	ft_inputs(t_fdf *map_data, mlx_t *mlx)
{
	map_data->angle_data->angle_x = 0;
	map_data->angle_data->angle_y = 0;
	map_data->angle_data->angle_z = 0;
	map_data->angle_data->zoom = 1;

	if (mlx_is_key_down(mlx, MLX_KEY_W))
		ft_modcoord(map_data, 0); // rotation vers l'avant
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		ft_modcoord(map_data, 1); // rotation vers l'arriere
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		ft_modcoord(map_data, 2); // rotation vers la droite
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		ft_modcoord(map_data, 3); // rotation vers la gauche
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT))
		ft_modcoord(map_data, 4); // zoom avant
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_CONTROL))
		ft_modcoord(map_data, 5); // zoom arriere
}

// faire une fonction bresenham

// faire une fonction pour convertir les coordonnees pour isometrique

// faire une fonction pour afficher les pixels
