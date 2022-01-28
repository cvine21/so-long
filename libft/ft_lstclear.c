/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:06:02 by cvine             #+#    #+#             */
/*   Updated: 2022/01/14 19:57:59 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nextel;

	if (lst && *lst && del)
	{
		while (*lst)
		{
			nextel = (*lst)->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = nextel;
		}
		*lst = NULL;
	}
}
