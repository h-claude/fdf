/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:07:42 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/02 22:00:21 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;

	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	i = 0;
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}*/

char	*ft_strdup(const char *s1)
{
	int		src_len;
	char	*dest;
	int		i;

	i = 0;
	src_len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * src_len + 1);
	if (!dest)
		return (0);
	ft_memset(dest, 0, src_len + 1);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}