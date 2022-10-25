/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:22:16 by htsang            #+#    #+#             */
/*   Updated: 2022/10/25 18:31:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	**tmp_lst;

	if (lst && del)
	{
		while (*lst)
		{
			tmp_lst = lst;
			lst = &(*lst)->next;
			ft_lstdelone(*tmp_lst, del);
		}
	}
}
