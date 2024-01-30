/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:43:19 by hclaude           #+#    #+#             */
/*   Updated: 2023/11/01 18:53:55 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*target1;
	const char	*target2;

	i = 0;
	target1 = s1;
	target2 = s2;
	if (n == 0)
		return (0);
	while (i + 1 < n && target1[i] == target2[i])
		i++;
	return ((unsigned char)target1[i] - (unsigned char)target2[i]);
}
