/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:09 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/02 15:31:44 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
//char	*ft_strjoin(char const *s1, char const *s2);
//char	*ft_substr(char const *s, unsigned int start, size_t len);
//size_t	ft_strlen(const char *s);
//void	ft_bzero(void *s, size_t n);
//void	*ft_calloc(size_t count, size_t size);

#endif