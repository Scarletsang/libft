/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:44:51 by htsang            #+#    #+#             */
/*   Updated: 2023/06/12 12:52:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/stringbuilder.h"

struct s_sb_action	sb_action_append(const char *str)
{
	return ((struct s_sb_action){
		.entry_str = str,
		.field_validator = 0
	});
}

struct s_sb_action	sb_action_append_len(const char *str, \
const size_t str_len)
{
	return ((struct s_sb_action){
		.entry_str = str,
		.entry_str_len = str_len,
		.field_validator = 0 | SB_ENTRY_STR_LEN_BIT
	});
}

struct s_sb_action	sb_action_insert(const char *str, \
const size_t edit_start)
{
	return ((struct s_sb_action){
		.entry_str = str,
		.edit_start = edit_start,
		.field_validator = 0 | SB_EDIT_START_BIT
	});
}

struct s_sb_action	sb_action_insert_len(const char *str, \
const size_t str_len, const size_t edit_start)
{
	return ((struct s_sb_action){
		.entry_str = str,
		.entry_str_len = str_len,
		.edit_start = edit_start,
		.field_validator = 0 | SB_ENTRY_STR_LEN_BIT | SB_EDIT_START_BIT
	});
}
