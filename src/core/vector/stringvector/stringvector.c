/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringvector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:36:34 by htsang            #+#    #+#             */
/*   Updated: 2023/07/04 20:54:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/vector/stringvector.h"

int	ft_stringvector_init(t_ft_stringvector *stringv, size_t capacity)
{
	if (ft_vector_init(stringv, sizeof(char *), capacity + 1, \
		ft_vector_copy_string))
		return (EXIT_FAILURE);
	ft_stringvector_append(stringv, NULL);
	return (EXIT_SUCCESS);
}

/**
 * @return The item at the given index.
*/
char	*ft_stringvector_get(const t_ft_stringvector *stringv, size_t index)
{
	return (ft_vector_get(stringv, index));
}

/**
 * @brief Set a given data at an index of the vector.
 * @return The given data.
*/
char	*ft_stringvector_set(t_ft_stringvector *stringv, size_t index, \
char *string)
{
	return (ft_vector_set(stringv, index, string));
}

int	ft_stringvector_resize(t_ft_stringvector *stringv)
{
	return (ft_vector_resize(stringv));
}

void	ft_stringvector_free(t_ft_stringvector *stringv)
{
	t_ft_vector_iterator	iterator;
	char					*current;

	ft_vector_iterator_begin(&iterator, stringv);
	while (!iterator.is_end)
	{
		current = (char *)ft_vector_iterator_current(&iterator);
		if (current)
			free(current);
		ft_vector_iterator_next(&iterator);
	}
	ft_vector_free(stringv);
}
