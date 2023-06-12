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

#include "LIBFT/stringbuilder/sb_iterator.h"

void	sb_iterator_init(t_sb_iterator *iterator, const t_vector *vector)
{
	vector_iterator_init(iterator, vector);
}

int	sb_iterator_next(t_sb_iterator *iterator)
{
	return (vector_iterator_next(iterator));
}

int	sb_iterator_prev(t_sb_iterator *iterator)
{
	return (vector_iterator_prev(iterator));
}

char	sb_iterator_current(t_sb_iterator *iterator)
{
	return (*(char *) vector_iterator_current(iterator));
}

bool	sb_iterator_is_end(t_sb_iterator *iterator)
{
	return (vector_iterator_is_end(iterator));
}
