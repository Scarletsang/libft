/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:22:16 by htsang            #+#    #+#             */
/*   Updated: 2023/06/12 12:41:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/list.h"

/**
** @brief Clear all memory that is used by the given linked list.
** 
** @param lst: the memory address of the pointer pointing
** to the start of linked list.
** @param del: the delete function that is used to delete the content
** of each node of the linked list.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp_lst;

	if (lst && del)
	{
		while (*lst)
		{
			tmp_lst = *lst;
			*lst = (*lst)->next;
			ft_lstdelone(tmp_lst, del);
		}
	}
}
