/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:10:34 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/07 17:26:27 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// this function convert hexa to int32

static int32_t	hexa_to_int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (10 + (c - 'a'));
	return (-1);
}

static void	put_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}

int32_t	get_the_color(char *hexStr)
{
	int32_t	result;
	int		val;

	if (ft_strncmp(hexStr, "0x", 2) != 0)
		return (-1);
	put_lowercase(hexStr + 2);
	result = 0;
	hexStr += 2;
	while (*hexStr)
	{
		val = hexa_to_int(*hexStr++);
		if (val == -1)
			return (-1);
		result = (result << 4) | val;
	}
	return (result);
}
