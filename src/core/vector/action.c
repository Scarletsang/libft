/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:26:09 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/07/03 17:10:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/vector.h"
#include "vector_internal.h"

void	*ft_vector_append(t_ft_vector *vector, void *data)
{
	void	*element;

	if (vector->size == vector->capacity)
		if (ft_vector_resize(vector))
			return (NULL);
	element = ft_vector_set(vector, vector->size, data);
	vector->size++;
	return (element);
}

void	*ft_vector_insert(t_ft_vector *vector, void *data, size_t index)
{
	void	*element;

	if (index > vector->size)
		return (NULL);
	if (vector->size == vector->capacity)
		if (ft_vector_resize(vector))
			return (NULL);
	ft_vector_buffer_shift(vector, index + 1, index);
	element = ft_vector_set(vector, index, data);
	vector->size++;
	return (element);
}

int	ft_vector_remove(t_ft_vector *vector, size_t index)
{
	if (index >= vector->size)
		return (EXIT_FAILURE);
	if (index + 1 < vector->size)
		ft_vector_buffer_shift(vector, index, index + 1);
	vector->size--;
	return (EXIT_SUCCESS);
}
