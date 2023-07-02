/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipper.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:14:25 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/07/02 01:03:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIPPER_H
# define CLIPPER_H

# include <stddef.h>
# include "LIBFT/slice.h"
# include "LIBFT/stringbuilder.h"

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
 * @param lbound The start of the substring, aka the index of the first
 * character of the substring.
 * @param rbound The right bound of the substring, aka next index after the last
 * character of the substring.
*/
struct s_ft_sb_clipper
{
	const t_ft_sb	*sb;
	size_t			lbound;
	size_t			rbound;
};

void		ft_sb_clipper_init(struct s_ft_sb_clipper *clipper, \
const t_ft_sb *sb);

int			ft_sb_clipper_move_lbound(struct s_ft_sb_clipper *clipper);

int			ft_sb_clipper_move_rbound(struct s_ft_sb_clipper *clipper);

char		ft_sb_clipper_at_lbound(\
const struct s_ft_sb_clipper *clipper);

char		ft_sb_clipper_at_rbound(\
const struct s_ft_sb_clipper *clipper);

/**
 * @brief Finds the occurance of two strings in a string builder, and sets the
 * bounds of the clipper to the area between the two strings. The first string
 * moves the left bound, and the second string moves the right bound. If any of
 * the parameters are NULL, the clipper will not move the corresponding bound.
 * If any of the given strings is not found, the clipper will remain unchanged.
 * 
 * For example, given the string builder's buffer: "HELLO!target!WORLD", 
 * ft_sb_clipper_area(sb, "Hello", "World") will set the clipper's bounds at
 * both exclamation marks, and ft_sb_clipper_run(sb) will produce "!target!".
 * 
 * @param clipper The clipper to be modified.
 * @param start_match The string to be found to move the left bound.
 * @param end_match The string to be found to move the right bound.
*/
int			ft_sb_clipper_area(struct s_ft_sb_clipper *clipper, \
const char *start_match, const char *end_match);

/**
 * @brief Creates a null-terminated substring from a string builder clipper.
*/
char		*ft_sb_clipper_run(const struct s_ft_sb_clipper *clipper);

t_ft_str	ft_sb_clipper_slice(const struct s_ft_sb_clipper *clipper);

#endif