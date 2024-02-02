/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:34:07 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/02 17:58:38 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*target;

	i = 0;
	target = s;
	while (i < n)
		target[i++] = '\0';
}
*/
void ft_bzero(void *s, size_t n)
{
    char *target = s;
    while (n--)
        *target++ = '\0';
}