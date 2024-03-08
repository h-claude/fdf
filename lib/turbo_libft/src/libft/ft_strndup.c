/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:09:33 by moajili           #+#    #+#             */
/*   Updated: 2024/02/15 09:30:52 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (len < n)
		n = len;
	dup = (char *)ft_calloc(n + 1, sizeof(char));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, n);
	return (dup);
}
