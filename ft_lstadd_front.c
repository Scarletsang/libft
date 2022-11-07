/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:48:06 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 15:09:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** @brief Add a node to the start of linked list.
** Equivalence to the 'cons' function in Lisp.
**
** @param lst:   the memory address of the pointer pointing
** to the start of linked list.
** @param front: the node to be added
*/
void	ft_lstadd_front(t_list **lst, t_list *front)
{
	if (lst && front)
	{
		front->next = *lst;
		*lst = front;
	}
}
