/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:38:55 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/06/13 15:10:14 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/vector.h"
#include "vector_internal.h"

void	ft_vector_iterator_init(t_ft_vector_iterator *iterator, \
const t_ft_vector *vector)
{
	iterator->vector = vector;
	iterator->index = 0;
	iterator->current = NULL;
}

int	ft_vector_iterator_next(t_ft_vector_iterator *iterator)
{
	if (iterator->index < iterator->vector->size)
	{
		iterator->index++;
		iterator->current = NULL;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	ft_vector_iterator_prev(t_ft_vector_iterator *iterator)
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
 * moved, see ft_vector_iterator_next and ft_vector_iterator_prev.
 */
void	*ft_vector_iterator_current(t_ft_vector_iterator *iterator)
{
	if (iterator->current == NULL)
		iterator->current = ft_vector_get(iterator->vector, iterator->index);
	return (iterator->current);
}

bool	ft_vector_iterator_is_end(const t_ft_vector_iterator *iterator)
{
	return (iterator->index == iterator->vector->size);
}
