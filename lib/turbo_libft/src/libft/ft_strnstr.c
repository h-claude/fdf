/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:53:06 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/03 20:22:56 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	little_len = ft_strlen(little);
	i = 0;
	if ((!big || !little) && len == 0)
		return (NULL);
	if (little_len == 0)
		return ((char *)big);
	while (big[i] != '\0' && len >= i + little_len)
	{
		if (big[i] == little[0])
		{
			if (ft_strncmp(big + i, little, little_len) == 0)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
