/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipper.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:14:25 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/06/12 12:49:42 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIPPER_H
# define CLIPPER_H

# include "LIBFT/stringbuilder.h"
# include "LIBFT/stringbuilder/sb_iterator.h"
# include "LIBFT/vector.h"

//////////////////////////////////////////////////////////
////////     String Builder clipper interface   //////////
//////////////////////////////////////////////////////////

/**
 * @brief A string builder clipper creates a substring from a string builder.
 * It does essentially the same thing as substr, however substr only iterates
 * until it sees a null-terminator. In string builder, although it is also
 * null-terminated, it is possible to have null characters in the middle of the
 * string. Saving the left bound and right bound of the substring allows the
 * one to modify the bounds multiple times before actually creating the
 * substring.
 * @param sb The string builder to clip from. A clipper will not modify the
 * string builder.
 * @param lbound The left bound of the substring, aka the index of the first
 * character of the substring.
 * @param rbound The right bound of the substring, aka the index of the last
 * character of the substring.
*/
struct s_sb_clipper
{
	const t_sb	*sb;
	size_t		lbound;
	size_t		rbound;
};

void	sb_clipper_init(struct s_sb_clipper *clipper, const t_sb *sb);

int		sb_clipper_move_lbound(struct s_sb_clipper *clipper);

int		sb_clipper_move_rbound(struct s_sb_clipper *clipper);

/**
 * @brief Finds the occurance of two strings in a string builder, and sets the
 * bounds of the clipper to the area between the two strings. The first string
 * moves the left bound, and the second string moves the right bound. If any of
 * the parameters are NULL, the clipper will not move the corresponding bound.
 * If any of the given strings is not found, the clipper will remain unchanged.
 * 
 * For example, given the string builder's buffer: "HELLO!target!WORLD", 
 * sb_clipper_area(sb, "Hello", "World") will set the clipper's bounds at
 * both exclamation marks, and sb_clipper_run(sb) will produce "!target!".
 * 
 * @param clipper The clipper to be modified.
 * @param start_match The string to be found to move the left bound.
 * @param end_match The string to be found to move the right bound.
*/
int		sb_clipper_area(struct s_sb_clipper *clipper, const char *start_match, \
const char *end_match);

/**
 * @brief Creates a null-terminated substring from a string builder clipper.
*/
char	*sb_clipper_run(const struct s_sb_clipper *clipper);

#endif