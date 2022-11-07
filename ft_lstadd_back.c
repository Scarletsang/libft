/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:12:38 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 15:09:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** @brief append a node to a linked list.
**
** @param lst:  the memory address of the pointer pointing
** to the start of linked list.
** @param back: the node to be appended
*/
void	ft_lstadd_back(t_list **lst, t_list *back)
{
	t_list	*last;

	if (!lst)
	{
		return ;
	}
	last = ft_lstlast(*lst);
	if (last)
	{
		last->next = back;
	}
	else
	{
		*lst = back;
	}
}
