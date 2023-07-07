/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:38:55 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/07/07 04:30:39 by htsang           ###   ########.fr       */
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
	if (iterator->is_end == TERNARY_TRUE)
		return (EXIT_FAILURE);
	if (iterator->index + 1 < iterator->vector->size)
	{
		iterator->index++;
		iterator->current = NULL;
		iterator->is_end = TERNARY_FALSE;
		return (EXIT_SUCCESS);
	}
	if (iterator->index < iterator->vector->size)
	{
		iterator->index++;
		iterator->current = NULL;
		iterator->is_end = TERNARY_TRUE;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	ft_vector_iterator_prev(t_ft_vector_iterator *iterator)
{
	if (iterator->is_end == TERNARY_UNKNOWN)
		return (EXIT_FAILURE);
	if (iterator->index > 0)
	{
		iterator->index--;
		iterator->current = NULL;
		iterator->is_end = TERNARY_FALSE;
		return (EXIT_SUCCESS);
	}
	if (iterator->index == 0)
	{
		iterator->current = NULL;
		iterator->is_end = TERNARY_UNKNOWN;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
