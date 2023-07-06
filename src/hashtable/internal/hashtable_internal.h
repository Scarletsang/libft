/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:21:10 by htsang            #+#    #+#             */
/*   Updated: 2023/07/06 15:14:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_INTERNAL_H
# define HASHTABLE_INTERNAL_H

# include <stdlib.h>
# include <stdbool.h>
# include "LIBFT/hashtable.h"
# include "LIBFT/string.h"

///////////////////////////////////////////
////////    private interface    //////////
///////////////////////////////////////////

struct s_ft_ht_entry	*ft_ht_get_entry(const t_ft_ht *ht, t_ft_str key);

struct s_ft_ht_entry	*ft_ht_get_empty_entry(const t_ft_ht *ht, \
t_ft_str key);

/**
 * @brief The hash function used to calculate the index of the storing entry.
*/
size_t					ft_hash(t_ft_str key, size_t capacity);

/**
 * @brief The hash function used to calculate the interval between each probing
 * for that particular entry.
*/
size_t					ft_hash_for_interval(t_ft_str key, size_t capacity);

#endif