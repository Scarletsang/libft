/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:44:51 by htsang            #+#    #+#             */
/*   Updated: 2023/07/06 14:56:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/stringbuilder.h"
#include "../stringbuilder_internal.h"
#include "field_validator.h"

struct s_ft_sb_action	ft_sb_action_append(t_ft_str str)
{
	return ((struct s_ft_sb_action){
		.entry_str = str.content,
		.entry_str_len = str.size,
		.field_validator = 0
	});
}

struct s_ft_sb_action	ft_sb_action_insert(t_ft_str str, \
const size_t edit_start)
{
	return ((struct s_ft_sb_action){
		.entry_str = str.content,
		.entry_str_len = str.size,
		.edit_start = edit_start,
		.field_validator = 0 | SB_EDIT_START_BIT
	});
}

struct s_ft_sb_action	ft_sb_action_delete(const size_t edit_start, \
const size_t edit_len)
{
	return ((struct s_ft_sb_action){
		.entry_str = NULL,
		.edit_start = edit_start,
		.edit_len = edit_len,
		.field_validator = 0 | SB_EDIT_START_BIT | SB_EDIT_LEN_BIT
	});
}

struct s_ft_sb_action	ft_sb_action_replace(t_ft_str str, \
const size_t edit_start, const size_t edit_len)
{
	return ((struct s_ft_sb_action){
		.entry_str = str.content,
		.entry_str_len = str.size,
		.edit_start = edit_start,
		.edit_len = edit_len,
		.field_validator = 0 | SB_EDIT_START_BIT | SB_EDIT_LEN_BIT
	});
}
