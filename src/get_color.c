/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deadchicken <deadchicken@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:10:34 by hclaude           #+#    #+#             */
/*   Updated: 2024/03/08 21:00:01 by deadchicken      ###   ########.fr       */
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
	while (*hexStr && *hexStr != '\n')
	{
		val = hexa_to_int(*hexStr++);
		if (val == -1)
			return (-1);
		result = (result << 4) | val;
	}
	if (ft_strlen(hexStr) < 8)
		result = (result << 8) | 0xFF;
	return (result);
}
