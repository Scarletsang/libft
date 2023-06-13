/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:19:15 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 15:21:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/list.h"

/**
** @brief Free the space of and clear the content of the given node.
**
** @param lst: the node
** @param del: the delete function that is used to clear the content.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del || !lst)
	{
		return ;
	}
	if (lst->content)
	{
		del(lst->content);
	}
	free(lst);
}
