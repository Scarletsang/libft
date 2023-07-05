/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:44:51 by htsang            #+#    #+#             */
/*   Updated: 2023/07/05 11:27:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/stringbuilder/sb_iterator.h"
#include "../stringbuilder_internal.h"

int	ft_sb_iterator_mut_insert(t_ft_sb_iterator *iterator, t_ft_str str)
{
	if (ft_sb_perform((t_ft_sb *) iterator->vector, \
		ft_sb_action_insert(str, iterator->index)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_sb_iterator_mut_delete(t_ft_sb_iterator *iterator, const size_t edit_len)
{
	return (ft_sb_perform((t_ft_sb *) iterator->vector, \
		ft_sb_action_delete(iterator->index, edit_len)));
}

int	ft_sb_iterator_mut_replace(t_ft_sb_iterator *iterator, t_ft_str str, \
const size_t edit_len)
{
	size_t	sb_size;

	sb_size = iterator->vector->size;
	if (ft_sb_perform((t_ft_sb *) iterator->vector, \
		ft_sb_action_replace(str, iterator->index, edit_len)))
		return (EXIT_FAILURE);
	if (iterator->vector->size > sb_size)
		iterator->index += iterator->vector->size - sb_size;
	else
		iterator->index += sb_size - iterator->vector->size;
	return (EXIT_SUCCESS);
}
