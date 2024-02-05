/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:42:38 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/03 22:11:18 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	lenght;

	if (!s)
		return (NULL);
	i = 0;
	lenght = ft_strlen(s);
	if (start >= lenght)
		return (ft_calloc(sizeof(char), 1)); // /!\//
	if (len + start > lenght)
		len = lenght - start;
	str = (char *)ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char			*ret;
// 	size_t			str_len;
// 	unsigned int	i;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	str_len = ft_strlen(s);
// 	if (start >= str_len)
// 		len = 0;
// 	if (len > (str_len + 1))
// 		len = str_len + 1;
// 	ret = (char *)malloc((len + 1) * sizeof(char));
// 	if (!ret)
// 		return (NULL);
// 	ft_memset(ret, 0, len + 1);
// 	while (s[start + i] && i < len)
// 	{
// 		ret[i] = s[start + i];
// 		i++;
// 	}
// 	while (i < len)
// 		ret[++i] = '\0';
// 	return (ret);
// }