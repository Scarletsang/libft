/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:29:12 by htsang            #+#    #+#             */
/*   Updated: 2023/07/05 10:51:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/stringbuilder/sb_iterator.h"

bool	ft_sb_iterator_has_next(const t_ft_sb_iterator *iterator)
{
	return (iterator->index + 2 < iterator->vector->size);
}

bool	ft_sb_iterator_has_prev(const t_ft_sb_iterator *iterator)
{
	return (ft_vector_iterator_has_prev(iterator));
}

int	ft_sb_iterator_next(t_ft_sb_iterator *iterator)
{
	if (iterator->is_end == TERNARY_TRUE)
		return (EXIT_FAILURE);
	if (iterator->index + 2 < iterator->vector->size)
	{
		iterator->index++;
		iterator->current = NULL;
		iterator->is_end = TERNARY_FALSE;
		return (EXIT_SUCCESS);
	}
	if (iterator->index + 1 < iterator->vector->size)
	{
		iterator->current = NULL;
		iterator->is_end = TERNARY_TRUE;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	ft_sb_iterator_prev(t_ft_sb_iterator *iterator)
{
	return (ft_vector_iterator_prev(iterator));
}
