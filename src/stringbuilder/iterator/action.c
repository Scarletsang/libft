/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:29:12 by htsang            #+#    #+#             */
/*   Updated: 2023/07/07 06:32:32 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/stringbuilder/sb_iterator.h"

bool	ft_sb_iterator_has_next(const t_ft_sb_iterator *iterator)
{
	return (iterator->index + 2 < iterator->vector->size);
}

bool	ft_sb_iterator_has_prev(const t_ft_sb_iterator *iterator)
{
	return (ft_vector_iterator_has_prev(iterator));
}

int	ft_sb_iterator_next(t_ft_sb_iterator *iterator)
{
	if (iterator->is_end == VECTOR_ITERATOR_RIGHT_END)
		return (VECTOR_ITERATOR_RIGHT_END);
	iterator->current = NULL;
	if (iterator->index + 2 < iterator->vector->size)
	{
		iterator->index++;
		iterator->is_end = VECTOR_ITERATOR_NOT_END;
		return (VECTOR_ITERATOR_NOT_END);
	}
	if (iterator->index + 1 < iterator->vector->size)
	{
		iterator->index++;
		iterator->is_end = VECTOR_ITERATOR_RIGHT_END;
		return (VECTOR_ITERATOR_RIGHT_END);
	}
	iterator->is_end = VECTOR_ITERATOR_RIGHT_END;
	return (VECTOR_ITERATOR_RIGHT_END);
}

int	ft_sb_iterator_prev(t_ft_sb_iterator *iterator)
{
	return (ft_vector_iterator_prev(iterator));
}
