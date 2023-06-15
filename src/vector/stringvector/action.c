/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:36:34 by htsang            #+#    #+#             */
/*   Updated: 2023/06/15 18:51:42 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/vector/stringvector.h"

char	*ft_stringvector_append(t_ft_vector *vector, char *data)
{
	return (ft_vector_append(vector, data));
}

char	*ft_stringvector_insert(t_ft_vector *vector, char *data, size_t index)
{
	return (ft_vector_insert(vector, data, index));
}

int	ft_stringvector_remove(t_ft_vector *vector, size_t index)
{
	char	*item;

	if (index >= vector->size)
		return (EXIT_FAILURE);
	item = ft_stringvector_get(vector, index);
	if (item)
		free(item);
	ft_vector_buffer_shift(vector, index, index + 1);
	vector->size--;
	return (EXIT_SUCCESS);
}
