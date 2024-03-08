/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:55:57 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/15 05:27:56 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int	countdigit(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0 && i != 8)
	{
		i++;
		n /= 16;
	}
	return (i);
}

int	ft_hexadecimal(unsigned int n, char format)
{
	char const	*base;
	int			i;
	char		*tab;

	i = countdigit(n);
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	tab = ft_calloc(i + 1, sizeof(char));
	if (!tab)
		return (ft_putstr(NULL));
	i--;
	while (i >= 0)
	{
		tab[i] = base[(n % 16)];
		n /= 16;
		i--;
	}
	i = ft_putstr(tab);
	free(tab);
	return (i);
}
