/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:46:25 by htsang            #+#    #+#             */
/*   Updated: 2022/10/25 18:26:26 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*result_ptr;

	if (!lst || !f || !del)
		return (NULL);
	result = ft_lstnew(f(lst->content));
	if (!result)
		return (NULL);
	result_ptr = result;
	lst = lst->next;
	while (lst)
	{
		result_ptr->next = ft_lstnew(f(lst->content));
		if (!result_ptr)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (result);
}
