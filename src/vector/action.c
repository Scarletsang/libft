/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:26:09 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/06/12 12:52:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/vector.h"

void	*vector_append(t_vector *vector, void *data)
{
	void	*element;

	if (vector->size == vector->capacity)
		if (vector_resize(vector))
			return (NULL);
	element = vector_set(vector, vector->size, data);
	vector->size++;
	return (element);
}

void	*vector_insert(t_vector *vector, void *data, size_t index)
{
	void	*element;

	if (index > vector->size)
		return (NULL);
	if (vector->size == vector->capacity)
		if (vector_resize(vector))
			return (NULL);
	vector_buffer_shift(vector, index + 1, index);
	element = vector_set(vector, index, data);
	vector->size++;
	return (element);
}

int	vector_remove(t_vector *vector, size_t index)
{
	if (index >= vector->size)
		return (EXIT_FAILURE);
	vector_buffer_shift(vector, index, index + 1);
	vector->size--;
	return (EXIT_SUCCESS);
}
