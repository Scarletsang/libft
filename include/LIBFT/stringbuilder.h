/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringbuilder.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:19:47 by htsang            #+#    #+#             */
/*   Updated: 2023/07/02 00:27:22 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGBUILDER_H
# define STRINGBUILDER_H

# include <stddef.h>
# include "LIBFT/slice.h"
# include "LIBFT/vector.h"

///////////////////////////////////////////////////
////////     String Builder interface    //////////
///////////////////////////////////////////////////

/**
 * @implements t_ft_vector interface
 * @brief The String builder allows easy and efficient construction of strings
 * from smaller pieces. It is implemented as a vector of characters.
*/
typedef t_ft_vector		t_ft_sb;
struct					s_ft_sb_action;

int						ft_sb_init(t_ft_sb *sb, const size_t capacity);

char					ft_sb_get(const t_ft_sb *sb, const size_t index);

/**
 * @brief Perform an operation on a string builder. It is expected to be used
 * with the string builder action functions. For example, to append a string to
 * a string builder, you would do:
 * ft_sb_perform(sb, ft_sb_action_append("Hello World!"));
*/
int						ft_sb_perform(t_ft_sb *sb, \
struct s_ft_sb_action action);

void					ft_sb_reset(t_ft_sb *sb);

int						ft_sb_resize(t_ft_sb *sb);

void					ft_sb_free(t_ft_sb *sb);

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
struct s_ft_sb_action
{
	const char		*entry_str;
	size_t			entry_str_len;
	size_t			edit_start;
	size_t			edit_len;
	unsigned int	field_validator : 2;
};

struct s_ft_sb_action	ft_sb_action_append(t_ft_str str);

struct s_ft_sb_action	ft_sb_action_insert(t_ft_str str, \
const size_t edit_start);

struct s_ft_sb_action	ft_sb_action_delete(const size_t edit_start, \
const size_t edit_len);

struct s_ft_sb_action	ft_sb_action_replace(t_ft_str str, \
const size_t edit_start, const size_t edit_len);

#endif