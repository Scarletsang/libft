/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_iterator.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:19:47 by htsang            #+#    #+#             */
/*   Updated: 2023/06/12 12:49:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SB_ITERATOR_H
# define SB_ITERATOR_H

# include "LIBFT/stringbuilder.h"
# include "LIBFT/vector.h"

///////////////////////////////////////////////////////////
////////     String Builder iterator interface   //////////
///////////////////////////////////////////////////////////

/**
 * @brief The String builder iterator iterates over the string contained
 * in the string builder.
*/
typedef t_vector_iterator	t_sb_iterator;

void						sb_iterator_init(t_sb_iterator *iterator, \
const t_vector *vector);

int							sb_iterator_next(t_sb_iterator *iterator);

int							sb_iterator_prev(t_sb_iterator *iterator);

char						sb_iterator_current(t_sb_iterator *iterator);

bool						sb_iterator_is_end(t_sb_iterator *iterator);

//////////////////////////////////////////////////////////
////////      manipulative iterator interface   //////////
//////////////////////////////////////////////////////////

/**
 * @section By default, an iterator is not allowed to modify the vector that it
 * is iterating on. However, string builder has a popular demand for editing
 * the string while iterating over it. Therefore, the following functions provide
 * interface to edit the string builder from where the iterator is currently
 * pointing at.
*/

int							sb_iterator_mut_insert(t_sb_iterator *iterator, \
const char *str);

int							sb_iterator_mut_insert_len(t_sb_iterator *iterator, \
const char *str, const size_t str_len);

int							sb_iterator_mut_delete(t_sb_iterator *iterator, \
const size_t edit_len);

int							sb_iterator_mut_replace(t_sb_iterator *iterator, \
const char *str, const size_t edit_len);

int							sb_iterator_mut_replace_len(\
t_sb_iterator *iterator, const char *str, const size_t str_len, \
const size_t edit_len);

#endif