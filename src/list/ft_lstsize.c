/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:54:15 by htsang            #+#    #+#             */
/*   Updated: 2023/06/12 12:41:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/list.h"

/**
** @param lst: the start of a linked list
** @return the size of the linked list
*/
int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
	{
		return (0);
	}
	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
