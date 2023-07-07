/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:38:55 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/07/07 06:30:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/vector.h"
#include "../vector_internal.h"

void	ft_vector_iterator_begin(t_ft_vector_iterator *iterator, \
const t_ft_vector *vector)
{
	iterator->vector = vector;
	iterator->index = 0;
	iterator->current = NULL;
	if (vector->size == 0)
		iterator->is_end = VECTOR_ITERATOR_RIGHT_END;
	else
		iterator->is_end = VECTOR_ITERATOR_NOT_END;
}

void	ft_vector_iterator_end(t_ft_vector_iterator *iterator, \
const t_ft_vector *vector)
{
	if (vector->size == 0)
	{
		iterator->index = 0;
		iterator->is_end = VECTOR_ITERATOR_LEFT_END;
	}
	else
	{
		iterator->index = vector->size - 1;
		iterator->is_end = VECTOR_ITERATOR_NOT_END;
	}
	iterator->vector = vector;
	iterator->current = NULL;
}

/**
 * @details If the current is not cached, then calculate it, otherwise simply
 * return the cached current. The cache is cleared whenever the iterator is
 * moved, see ft_vector_iterator_next and ft_vector_iterator_prev.
 */
void	*ft_vector_iterator_current(t_ft_vector_iterator *iterator)
{
	if (iterator->is_end && (iterator->index == 0 || iterator->index == \
		iterator->vector->size))
		return (NULL);
	if (iterator->current == NULL)
		iterator->current = ft_vector_get(iterator->vector, iterator->index);
	return (iterator->current);
}
