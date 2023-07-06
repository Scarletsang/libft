/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:08:04 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/07/07 01:46:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include <stddef.h>
# include "LIBFT/slice.h"
# include "LIBFT/vector.h"

///////////////////////////////////////////////
////////     hashtable interface     //////////
///////////////////////////////////////////////

/**
 * @implements  t_ft_vector interface
 * @brief The hashtable is implemented with open addressing, and double
 * hashing as the strategy for resolving collisions. One hash function is
 * used to calculate the index of the storing entry, and another hash function
 * is used to calculate the interval between each probing for that particular
 * entry.
*/
typedef t_ft_vector	t_ft_ht;
struct				s_ft_ht_entry;

/**
 * @brief This implementation of hashtable concern about ownership of the
 * the data store inside the hashtable. If a data is set to be owned by
 * the hashtable, hashtable has the responsibility to free the data when
 * the hashtable is freed or the data is updated. If a data is not owned
 * by the hashtable, the user has the responsibility to free the data.
 * Therefore each entry owned by the hashtable stores a cleaner function
 * that will be called when the entry is freed.
*/
typedef void		(*t_ft_ht_entry_cleaner)(void *);

int							ft_ht_init(t_ft_ht *ht, const size_t capacity);

t_ft_object					ft_ht_get(const t_ft_ht *ht, t_ft_str key);

/**
 * @brief When the cleaner function is specified, the entry is assumed to be
 * owned by the hashtable. The cleaner function will be called when the entry
 * is freed. Otherwise, user should pass NULL to the cleaner parameter.
*/
const struct s_ft_ht_entry	*ft_ht_set(t_ft_ht *ht, t_ft_str key, \
t_ft_object value, t_ft_ht_entry_cleaner cleaner);

int							ft_ht_resize(t_ft_ht *ht);

void						ft_ht_free(t_ft_ht *ht);

/**
 * @brief hashtable-specific functions
*/

const struct s_ft_ht_entry	*ft_ht_update(t_ft_ht *ht, t_ft_str key, \
t_ft_object value, t_ft_ht_entry_cleaner cleaner);

int							ft_ht_delete(t_ft_ht *ht, t_ft_str key);

//////////////////////////////////////////////////
////////   hashtable entry interface    //////////
//////////////////////////////////////////////////

/**
 * @brief The entry of the hashtable. Each entry stores a key, a value, and
 * a cleaner function. When the cleaner is not NULL, it means the entry is
 * owned by the hashtable, and the cleaner function will be run when the
 * entry is freed.
*/
struct s_ft_ht_entry
{
	char					*key;
	t_ft_object				value;
	bool					deleted;
	t_ft_ht_entry_cleaner	cleaner;
};

void						ft_ht_entry_init(struct s_ft_ht_entry *entry);

void						ft_ht_entry_delete(struct s_ft_ht_entry *entry);

int							ft_ht_entry_set_key(struct s_ft_ht_entry *entry, \
t_ft_str key);

int							ft_ht_entry_set_value(struct s_ft_ht_entry *entry, \
t_ft_object value, t_ft_ht_entry_cleaner cleaner);

////////////////////////////////////////////
////////      debugp printer      //////////
////////////////////////////////////////////

void						ft_ht_print(t_ft_ht *ht);

#endif