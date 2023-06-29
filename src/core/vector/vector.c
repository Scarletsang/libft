/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:13:19 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/06/29 03:43:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/vector.h"
#include "vector_internal.h"

int	ft_vector_init(t_ft_vector *vector, size_t item_size, size_t capacity, \
t_ft_vector_item_copier copier)
{
	vector->buffer = ft_calloc(capacity, item_size);
	if (!vector->buffer)
		return (EXIT_FAILURE);
	vector->capacity = capacity;
	vector->item_size = item_size;
	vector->size = 0;
	if (!copier)
		vector->copier = (t_ft_vector_item_copier) ft_vector_copy_char;
	else
		vector->copier = copier;
	return (EXIT_SUCCESS);
}

void	*ft_vector_get(const t_ft_vector *vector, size_t index)
{
	return (vector->buffer + (index * vector->item_size));
}

void	*ft_vector_set(t_ft_vector *vector, size_t index, void *data)
{
	void	*element;

	element = ft_vector_get(vector, index);
	vector->copier(element, data);
	return (element);
}

/**
 * @details Double the current capacity of the vector. If the capacity after
 * resizing exceeds SIZE_MAX, then the new capacity is set to SIZE_MAX.
*/
int	ft_vector_resize(t_ft_vector *vector)
{
	void	*old_buffer;
	size_t	new_capacity;

	if (vector->capacity == SIZE_MAX)
		return (EXIT_FAILURE);
	new_capacity = vector->capacity * 2;
	if (new_capacity > (SIZE_MAX / 2))
		new_capacity = SIZE_MAX;
	old_buffer = vector->buffer;
	vector->buffer = malloc(vector->item_size * new_capacity);
	if (!vector->buffer)
		return (EXIT_FAILURE);
	ft_vector_buffer_copy_from(vector, old_buffer, 0, vector->size);
	free(old_buffer);
	vector->capacity = new_capacity;
	return (EXIT_SUCCESS);
}

void	ft_vector_free(t_ft_vector *vector)
{
	if (vector->buffer)
		free(vector->buffer);
	vector->buffer = NULL;
	vector->item_size = 0;
	vector->size = 0;
	vector->capacity = 0;
	vector->copier = NULL;
}
