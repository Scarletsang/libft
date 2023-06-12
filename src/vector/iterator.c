/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:38:55 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/06/12 12:52:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/vector.h"

void	vector_iterator_init(t_vector_iterator *iterator, \
const t_vector *vector)
{
	iterator->vector = vector;
	iterator->index = 0;
	iterator->current = NULL;
}

int	vector_iterator_next(t_vector_iterator *iterator)
{
	if (iterator->index < iterator->vector->size)
	{
		iterator->index++;
		iterator->current = NULL;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	vector_iterator_prev(t_vector_iterator *iterator)
{
	if (iterator->index > 0)
	{
		iterator->index--;
		iterator->current = NULL;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

/**
 * @details If the current is not cached, then calculate it, otherwise simply
 * return the cached current. The cache is cleared whenever the iterator is
 * moved, see vector_iterator_next and vector_iterator_prev.
 */
void	*vector_iterator_current(t_vector_iterator *iterator)
{
	if (iterator->current == NULL)
		iterator->current = vector_get(iterator->vector, iterator->index);
	return (iterator->current);
}

bool	vector_iterator_is_end(const t_vector_iterator *iterator)
{
	return (iterator->index == iterator->vector->size);
}
