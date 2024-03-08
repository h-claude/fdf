/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:49:25 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/15 09:32:32 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <stdlib.h>

static int	countstr(char const *s, char c)
{
	int	i;
	int	nbstr;

	i = 0;
	nbstr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			nbstr++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (nbstr);
}

static void	freetab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	str = NULL;
}

static char	**sub(const char *s, char c, char **str, int len)
{
	size_t	i;
	size_t	sub_start;
	int		y;

	i = 0;
	sub_start = 0;
	y = 0;
	while (y < len)
	{
		while (s[i] == c && s[i])
			i++;
		sub_start = i;
		while (s[i] != c && s[i])
			i++;
		str[y++] = ft_substr(s, sub_start, i - sub_start);
		if (!str[y - 1])
			return (freetab(str), NULL);
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		len;

	if (!s)
		return (NULL);
	len = countstr(s, c);
	str = ft_calloc(len + 1, sizeof(char *));
	if (!str)
		return (NULL);
	if (!sub(s, c, str, len))
		return (NULL);
	return (str);
}
