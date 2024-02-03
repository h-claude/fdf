/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:28:12 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/02 21:40:10 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	size_t	i;

	dest = dst;
	i = 0;
	if (src == NULL && dst == NULL)
		return (dest);
	while (i < n)
	{
		dest[i] = *(char *)src;
		src++;
		i++;
	}
	return (dest);
}