/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:42:38 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/19 14:18:12 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	lenght;

	i = 0;
	if (!s)
		return (NULL);
	lenght = ft_strlen(s);
	if (start >= lenght)
	{
		str = ft_calloc(sizeof(char), 1);
		return (str);
	}
	if (len + start > lenght)
		len = lenght - start;
	str = (char *)ft_calloc(sizeof(char), len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
