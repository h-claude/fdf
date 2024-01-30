/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:32:58 by hclaude           #+#    #+#             */
/*   Updated: 2023/11/04 02:49:21 by hclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*oui;
	t_list	*non;

	if (!lst || !del)
		return ;
	oui = *lst;
	while (oui)
	{
		non = oui->next;
		ft_lstdelone(oui, (*del));
		oui = non;
	}
	*lst = NULL;
}
