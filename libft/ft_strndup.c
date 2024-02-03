/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:09:33 by moajili           #+#    #+#             */
/*   Updated: 2024/02/02 21:11:33 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strndup(const char *s, size_t n)
{
    char *dup;
    size_t len;

    len = ft_strlen(s);
    if (len < n)
        n = len;
    dup = (char *)ft_calloc(n + 1, sizeof(char));
    if (!dup)
        return (NULL);
    ft_memcpy(dup, s, n);
    return (dup);
}