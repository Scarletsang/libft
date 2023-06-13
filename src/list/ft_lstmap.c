/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:46:25 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 15:22:06 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/list.h"

/**
** @brief Same as lstnew, but able to also delete the content using
** the function function pointer when memory allocation fails.
**
** @param content: the content to generate a new node.
** @param del(content): a function to delete the content of a node
** when malloc allocation fails.
*/
static t_list	*ft_lstnew_del(void *content, void (*del)(void *))
{
	t_list	*node;

	node = ft_lstnew(content);
	if (!node)
	{
		del(content);
		return (NULL);
	}
	return (node);
}

/**
** @brief Map the content of a linked list to the content
** of a new linked list. A new linked list is created based on
** applying a function to every element of the given linked list.
**
** @param lst: the start of a linked list.
** @param f:   the function to be applied on every iteration to create
** new node on the new linked list.
** @param del: the function to clear teh new linked list if any malloc
** fails during the construction of the new linked list.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*result_ptr;

	if (!lst || !f || !del)
		return (NULL);
	result = ft_lstnew_del(f(lst->content), del);
	if (!result)
		return (NULL);
	result_ptr = result;
	while (lst->next)
	{
		lst = lst->next;
		result_ptr->next = ft_lstnew_del(f(lst->content), del);
		result_ptr = result_ptr->next;
		if (!result_ptr)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
	}
	return (result);
}
