/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:42:01 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/05 13:37:07 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	y;
	size_t	len;

	if (ft_memchr(dst, '\0', dstsize) == NULL)
		return (ft_strlen(src) + dstsize);
	i = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= i)
		return (ft_strlen(src) + dstsize);
	len = ft_strlen(dst) + ft_strlen(src);
	y = 0;
	while (i < (dstsize - 1) && src[y])
		dst[i++] = src[y++];
	dst[i] = '\0';
	return (len);
}
