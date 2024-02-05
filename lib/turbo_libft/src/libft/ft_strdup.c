/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:07:42 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/03 22:00:48 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;

	str = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

// char	*ft_strdup(const char *s1)
// {
// 	int		src_len;
// 	char	*dest;
// 	int		i;

// 	i = 0;
// 	src_len = ft_strlen(s1);
// 	dest = (char *)malloc(sizeof(char) * src_len + 1);
// 	if (!dest)
// 		return (0);
// 	ft_memset(dest, 0, src_len + 1);
// 	while (s1[i])
// 	{
// 		dest[i] = s1[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }