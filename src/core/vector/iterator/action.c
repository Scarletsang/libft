/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:38:55 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/07/07 06:31:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/vector.h"
#include "../vector_internal.h"

bool	ft_vector_iterator_has_next(const t_ft_vector_iterator *iterator)
{
	return (iterator->index + 1 < iterator->vector->size);
}

bool	ft_vector_iterator_has_prev(const t_ft_vector_iterator *iterator)
{
	return (iterator->index > 0);
}

int	ft_vector_iterator_next(t_ft_vector_iterator *iterator)
{
	if (iterator->is_end == VECTOR_ITERATOR_RIGHT_END)
		return (VECTOR_ITERATOR_RIGHT_END);
	iterator->current = NULL;
	if (iterator->index + 1 == iterator->vector->size)
	{
		iterator->index++;
		iterator->is_end = VECTOR_ITERATOR_RIGHT_END;
		return (VECTOR_ITERATOR_RIGHT_END);
	}
	if (iterator->index < iterator->vector->size)
	{
		iterator->index++;
		iterator->is_end = VECTOR_ITERATOR_NOT_END;
		return (VECTOR_ITERATOR_NOT_END);
	}
	iterator->is_end = VECTOR_ITERATOR_RIGHT_END;
	return (VECTOR_ITERATOR_RIGHT_END);
}

int	ft_vector_iterator_prev(t_ft_vector_iterator *iterator)
{
	if (iterator->is_end == VECTOR_ITERATOR_LEFT_END)
		return (VECTOR_ITERATOR_LEFT_END);
	iterator->current = NULL;
	if (iterator->index == 0)
	{
		iterator->is_end = VECTOR_ITERATOR_LEFT_END;
		return (VECTOR_ITERATOR_LEFT_END);
	}
	if (iterator->index > 0)
	{
		iterator->index--;
		iterator->is_end = VECTOR_ITERATOR_NOT_END;
		return (VECTOR_ITERATOR_NOT_END);
	}
	iterator->is_end = VECTOR_ITERATOR_LEFT_END;
	return (VECTOR_ITERATOR_LEFT_END);
}
