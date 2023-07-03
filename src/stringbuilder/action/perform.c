/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:09:57 by htsang            #+#    #+#             */
/*   Updated: 2023/07/03 18:15:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/stringbuilder.h"
#include "../stringbuilder_internal.h"
#include "field_validator.h"

static void	sb_injection_word(t_ft_sb *sb, struct s_ft_sb_action *action)
{
	ft_vector_buffer_shift(sb, action->edit_start + action->entry_str_len, \
		action->edit_start + action->edit_len);
	ft_vector_buffer_copy_from(sb, (void *) action->entry_str, \
		action->edit_start, action->entry_str_len);
	sb->size += action->entry_str_len - action->edit_len;
	ft_vector_set(sb, sb->size - 1, "\0");
}

static int	sb_perform_delete(t_ft_sb *sb, struct s_ft_sb_action *action)
{
	size_t	remaining_size;

	if (action->edit_start >= sb->size)
		return (EXIT_FAILURE);
	if (action->edit_len == 0)
		return (EXIT_SUCCESS);
	remaining_size = sb->size - action->edit_start;
	if (action->edit_len >= remaining_size)
	{
		ft_vector_set(sb, action->edit_start, "\0");
		sb->size = action->edit_start + 1;
		return (EXIT_SUCCESS);
	}
	remaining_size -= action->edit_len;
	ft_vector_buffer_shift(sb, action->edit_start, \
		action->edit_start + action->edit_len);
	sb->size -= action->edit_len;
	ft_vector_set(sb, sb->size - 1, "\0");
	return (EXIT_SUCCESS);
}

/**
 * @brief Replace a substring with another string.
 * @details
 * 1. Check if replacement index is valid. Otherwise, return error.
 * 2. Check if buffer has enough space to insert the string. Otherwise, resize
 * the buffer.
 * 3. Offset the substring after the replacement index by the difference
 * between the replacement string length and the substring length.
 * 4. Copy the replacement string at the replacement index.
*/
static int	sb_perform_replace(t_ft_sb *sb, struct s_ft_sb_action *action)
{
	if (action->edit_start >= sb->size)
		return (EXIT_FAILURE);
	if (action->edit_start + action->edit_len >= sb->size)
		action->edit_len = sb->size - action->edit_start - 1;
	if (action->entry_str_len > action->edit_len)
	{
		while (sb->size + action->entry_str_len - \
			action->edit_len >= sb->capacity)
			if (ft_sb_resize(sb))
				return (EXIT_FAILURE);
	}
	sb_injection_word(sb, action);
	return (EXIT_SUCCESS);
}

/**
 * @brief Insert a string at a given position in the buffer.
 * @details
 * 1. Check if insertion index is valid. Otherwise, return error.
 * 2. Check if buffer has enough space to insert the string. Otherwise, resize
 * the buffer.
 * 3. Offset the substring after the insertion index by the insertion string
 * length.
 * 4. Copy the insertion string at the insertion index.
*/
static int	sb_perform_insert(t_ft_sb *sb, struct s_ft_sb_action *action)
{
	if (action->edit_start >= sb->size)
		return (EXIT_FAILURE);
	while (sb->size + action->entry_str_len >= sb->capacity)
	{
		if (ft_sb_resize(sb))
			return (EXIT_FAILURE);
	}
	sb_injection_word(sb, action);
	return (EXIT_SUCCESS);
}

/**
 * @details If entry_str is not specified, then it is a delete operation.
 * If entry_str_len is not specified, then the whole entry_str will be
 * taken into account, so it will be set to the length of the entry_str. If
 * edit_len is set, then it is a replace operation. Eventually, an append
 * operation is the same as an insert operation, except that the insertion
 * happens at the end of the buffer. An append operation does not specify
 * an edit_start, so it will be set to the index of the last character of
 * the buffer.
*/
int	ft_sb_perform(t_ft_sb *sb, struct s_ft_sb_action action)
{
	if (!action.entry_str)
		return (sb_perform_delete(sb, &action));
	if (ft_sb_action_has_edit_len(&action))
	{
		return (sb_perform_replace(sb, &action));
	}
	action.edit_len = 0;
	action.field_validator |= SB_EDIT_LEN_BIT;
	if (!ft_sb_action_has_edit_start(&action))
	{
		action.edit_start = sb->size - 1;
		action.field_validator |= SB_EDIT_START_BIT;
	}
	return (sb_perform_insert(sb, &action));
}
