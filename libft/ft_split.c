/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:49:25 by hclaude           #+#    #+#             */
/*   Updated: 2023/11/07 16:28:14 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	**sub(const char *s, char c, char **str)
{
	size_t	i;
	size_t	sub_start;
	int		y;
	int		len;

	i = 0;
	sub_start = 0;
	y = 0;
	len = countstr(s, c);
	while (y < len)
	{
		while (s[i] == c && s[i])
			i++;
		sub_start = i;
		while (s[i] != c && s[i])
			i++;
		str[y++] = ft_substr(s, sub_start, i - sub_start);
		if (!str[y - 1])
		{
			freetab(str);
			return (NULL);
		}
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = ft_calloc(countstr(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	if (!sub(s, c, str))
	{
		return (NULL);
	}
	return (str);
}
