/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:16:44 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/07/03 18:16:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/vector.h"
#include "vector_internal.h"

/**
 * @details If the vector is empty, nothing happens. If the buffer need to be
 * shifted to the right, then it copies the buffer from the end to the start.
 * If the buffer need to be shifted to the left, then it copies the buffer
 * from the start to the end. The implementation is exactly like memmove, but
 * it copies with the vector_setter for more efficient copying.
*/
void	ft_vector_buffer_shift(t_ft_vector *vector, size_t to, size_t from)
{
	size_t	distance;

	if (vector->size == 0)
		return ;
	if ((from < to) && (to < vector->capacity))
	{
		distance = to - from;
		to = vector->size - 1 + distance;
		from += distance;
		while (to > from)
		{
			ft_vector_set(vector, to, ft_vector_get(vector, to - distance));
			to--;
		}
		ft_vector_set(vector, to, ft_vector_get(vector, to - distance));
	}
	else if ((from > to) && (from < vector->capacity))
	{
		distance = from - to;
		while ((to + distance) < vector->size)
		{
			ft_vector_set(vector, to, ft_vector_get(vector, (to + distance)));
			to++;
		}
	}
}

void	ft_vector_buffer_copy_from(t_ft_vector *vector, void *buffer, \
size_t index, size_t copy_amount)
{
	while ((index < vector->capacity) && (copy_amount > 0))
	{
		ft_vector_set(vector, index, buffer);
		buffer += vector->item_size;
		index++;
		copy_amount--;
	}
}
