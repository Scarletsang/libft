/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:12:38 by htsang            #+#    #+#             */
/*   Updated: 2022/10/25 18:30:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *back)
{
	t_list	*last;

	if (lst)
	{
		return ;
	}
	last = ft_lstlast(*lst);
	if (last)
	{
		last->next = back;
	}
}
