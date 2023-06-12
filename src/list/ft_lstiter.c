/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:41:26 by htsang            #+#    #+#             */
/*   Updated: 2023/06/12 12:41:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/list.h"

/**
** @brief Iterate on a linked list, apply a function to
** change the content of each node of the linked list. Since
** this function will not make a new linked list, the function
** can also be used to invoke side effects that depends purely
** on the content on each node.
**
** @param lst: the start of the linked list
** @param f:   the function to be applied during iteration
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
