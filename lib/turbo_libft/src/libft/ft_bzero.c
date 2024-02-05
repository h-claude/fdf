/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:34:07 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/03 21:54:36 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*target;

	target = s;
	while (n--)
		*target++ = '\0';
}

// void	ft_bzero(void *s, size_t n)
// {
//     char	*target;

// 	target = s;
//     while (n--)
//         *target++ = '\0';
// }
