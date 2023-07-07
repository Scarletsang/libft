/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:44:51 by htsang            #+#    #+#             */
/*   Updated: 2023/07/07 06:33:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/stringbuilder/sb_iterator.h"
#include "../stringbuilder_internal.h"

int	ft_sb_iterator_mut_insert(t_ft_sb_iterator *iterator, t_ft_str str)
{
	if (str.size == 0)
		return (EXIT_SUCCESS);
	if (ft_sb_perform((t_ft_sb *) iterator->vector, \
		ft_sb_action_insert(str, iterator->index)))
		return (EXIT_FAILURE);
	iterator->current = NULL;
	if (iterator->index + 1 >= iterator->vector->size)
		iterator->is_end = VECTOR_ITERATOR_RIGHT_END;
	else if (iterator->is_end != VECTOR_ITERATOR_LEFT_END)
		iterator->is_end = TERNARY_FALSE;
	return (EXIT_SUCCESS);
}

int	ft_sb_iterator_mut_delete(t_ft_sb_iterator *iterator, const size_t edit_len)
{
	if (edit_len == 0)
		return (EXIT_SUCCESS);
	if (ft_sb_perform((t_ft_sb *) iterator->vector, \
		ft_sb_action_delete(iterator->index, edit_len)))
		return (EXIT_FAILURE);
	iterator->current = NULL;
	if (iterator->index + 1 >= iterator->vector->size)
		iterator->is_end = VECTOR_ITERATOR_RIGHT_END;
	else if (iterator->is_end != VECTOR_ITERATOR_LEFT_END)
		iterator->is_end = TERNARY_FALSE;
	return (EXIT_SUCCESS);
}

int	ft_sb_iterator_mut_replace(t_ft_sb_iterator *iterator, t_ft_str str, \
const size_t edit_len)
{
	if (ft_sb_perform((t_ft_sb *) iterator->vector, \
		ft_sb_action_replace(str, iterator->index, edit_len)))
		return (EXIT_FAILURE);
	iterator->current = NULL;
	if (iterator->index + 1 >= iterator->vector->size)
		iterator->is_end = VECTOR_ITERATOR_RIGHT_END;
	else if (iterator->is_end != VECTOR_ITERATOR_LEFT_END)
		iterator->is_end = TERNARY_FALSE;
	return (EXIT_SUCCESS);
}
