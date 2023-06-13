/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:44:00 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 15:22:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/list.h"

/**
** @brief Creates a new node with the given content.
**
** @param content: The pointer to be stored in the content
** of the newly created node.
** @return a new node/a size-1 linked list, where lst.next is
** pointing to NULL.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *) malloc(sizeof(t_list));
	if (!lst)
	{
		return (NULL);
	}
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
