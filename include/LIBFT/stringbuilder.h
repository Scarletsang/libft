/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringbuilder.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:19:47 by htsang            #+#    #+#             */
/*   Updated: 2023/06/12 12:50:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGBUILDER_H
# define STRINGBUILDER_H

# include <stdlib.h>
# include <stdbool.h>
# include "LIBFT/libft.h"
# include "LIBFT/vector.h"

///////////////////////////////////////////////////
////////     String Builder interface    //////////
///////////////////////////////////////////////////

/**
 * @implements t_vector interface
 * @brief The String builder allows easy and efficient construction of strings
 * from smaller pieces. It is implemented as a vector of characters.
*/
typedef t_vector			t_sb;
struct						s_sb_action;

int							sb_init(t_sb *sb, const size_t capacity);

char						sb_get(const t_sb *sb, const size_t index);

/**
 * @brief Perform an operation on a string builder. It is expected to be used
 * with the string builder action functions. For example, to append a string to
 * a string builder, you would do:
 * sb_perform(sb, sb_action_append("Hello World!"));
*/
int							sb_perform(t_sb *sb, struct s_sb_action action);

int							sb_resize(t_sb *sb);

void						sb_free(t_sb *sb);

/**
 * @brief A String Builder action represents an operation to be performed on a
 * string builder.
 * @param entry_str The string to be inserted into the string builder.
 * @param entry_str_len The length of the string to be inserted into the string
 * builder.
 * @param edit_start The index of the string builder where the string will be
 * inserted.
 * @param edit_len The length of the string to be replaced in the string builder.
 * @param field_validator A bit field that indicates which fields are valid. It
 * is needed because some actions may not need all the fields.
*/
struct s_sb_action
{
	const char		*entry_str;
	size_t			entry_str_len;
	size_t			edit_start;
	size_t			edit_len;
	unsigned int	field_validator : 3;
};

struct s_sb_action			sb_action_append(const char *str);

struct s_sb_action			sb_action_append_len(const char *str, \
const size_t str_len);

struct s_sb_action			sb_action_insert(const char *str, \
const size_t edit_start);

struct s_sb_action			sb_action_insert_len(const char *str, \
const size_t str_len, const size_t edit_start);

struct s_sb_action			sb_action_delete(const size_t edit_start, \
const size_t edit_len);

struct s_sb_action			sb_action_replace(const char *str, \
const size_t edit_start, const size_t edit_len);

struct s_sb_action			sb_action_replace_len(const char *str, \
const size_t str_len, const size_t edit_start, const size_t edit_len);

/////////////////////////////////////////////
////////     Private interface     //////////
/////////////////////////////////////////////

/**
 * @brief A bit field that indicates which fields are valid. It is needed
 * because the action functions will not fill in all the fields, the unfilled
 * fields will wither be filled when sb_perform is called, or if the action
 * does not require the field, it will be ignored.
*/
enum e_sb_validator_bit
{
	SB_ENTRY_STR_LEN_BIT = 0b1,
	SB_EDIT_START_BIT = 0b10,
	SB_EDIT_LEN_BIT = 0b100
};

void						sb_action_set_validator_bit(\
struct s_sb_action *action, enum e_sb_validator_bit bit);

void						sb_action_flip_validator_bit(\
struct s_sb_action *action, enum e_sb_validator_bit bit);

bool						sb_action_has_entry_str_len(\
struct s_sb_action *action);

bool						sb_action_has_edit_start(\
struct s_sb_action *action);

bool						sb_action_has_edit_len(struct s_sb_action *action);

#endif