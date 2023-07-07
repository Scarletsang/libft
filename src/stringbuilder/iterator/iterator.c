/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:38:55 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/07/07 06:33:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/stringbuilder/sb_iterator.h"

void	ft_sb_iterator_begin(t_ft_sb_iterator *iterator, \
const t_ft_sb *sb)
{
	iterator->vector = sb;
	iterator->index = 0;
	iterator->current = NULL;
	if (sb->size <= 1)
		iterator->is_end = VECTOR_ITERATOR_RIGHT_END;
	else
		iterator->is_end = TERNARY_FALSE;
}

void	ft_sb_iterator_end(t_ft_sb_iterator *iterator, \
const t_ft_sb *sb)
{
	if (sb->size <= 1)
	{
		iterator->index = 0;
		iterator->is_end = VECTOR_ITERATOR_LEFT_END;
	}
	else
	{
		iterator->index = sb->size - 2;
		iterator->is_end = TERNARY_FALSE;
	}
	iterator->vector = sb;
	iterator->current = NULL;
}

char	ft_sb_iterator_current(t_ft_sb_iterator *iterator)
{
	if (iterator->current == NULL)
		iterator->current = ft_vector_get(iterator->vector, iterator->index);
	return (*(char *) iterator->current);
}
