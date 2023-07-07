/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_iterator.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:19:47 by htsang            #+#    #+#             */
/*   Updated: 2023/07/07 06:31:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SB_ITERATOR_H
# define SB_ITERATOR_H

# include <stddef.h>
# include <stdbool.h>
# include "LIBFT/stringbuilder.h"

///////////////////////////////////////////////////////////
////////     String Builder iterator interface   //////////
///////////////////////////////////////////////////////////

/**
 * @brief The String builder iterator iterates over the string contained
 * in the string builder.
*/
typedef t_ft_vector_iterator	t_ft_sb_iterator;

void	ft_sb_iterator_begin(t_ft_sb_iterator *iterator, \
const t_ft_sb *sb);

void	ft_sb_iterator_end(t_ft_sb_iterator *iterator, \
const t_ft_sb *sb);

int		ft_sb_iterator_next(t_ft_sb_iterator *iterator);

int		ft_sb_iterator_prev(t_ft_sb_iterator *iterator);

bool	ft_sb_iterator_has_next(const t_ft_sb_iterator *iterator);

bool	ft_sb_iterator_has_prev(const t_ft_sb_iterator *iterator);

char	ft_sb_iterator_current(t_ft_sb_iterator *iterator);

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

int		ft_sb_iterator_mut_insert(\
t_ft_sb_iterator *iterator, t_ft_str str);

int		ft_sb_iterator_mut_delete(\
t_ft_sb_iterator *iterator, const size_t edit_len);

int		ft_sb_iterator_mut_replace(\
t_ft_sb_iterator *iterator, t_ft_str str, const size_t edit_len);

#endif