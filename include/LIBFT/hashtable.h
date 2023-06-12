/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:08:04 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/06/12 12:50:44 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include <stdlib.h>
# include <stdbool.h>
# include "LIBFT/libft.h"
# include "LIBFT/vector.h"

///////////////////////////////////////////////
////////     hashtable interface     //////////
///////////////////////////////////////////////

/**
 * @implements  t_vector interface
 * @brief The hashtable is implemented with open addressing, and double
 * hashing as the strategy for resolving collisions. One hash function is
 * used to calculate the index of the storing entry, and another hash function
 * is used to calculate the interval between each probing for that particular
 * entry.
*/
typedef t_vector	t_ht;
struct				s_ht_entry;

/**
 * @brief This implementation of hashtable concern about ownership of the
 * the data store inside the hashtable. If a data is set to be owned by
 * the hashtable, hashtable has the responsibility to free the data when
 * the hashtable is freed or the data is updated. If a data is not owned
 * by the hashtable, the user has the responsibility to free the data.
 * Therefore each entry owned by the hashtable stores a cleaner function
 * that will be called when the entry is freed.
*/
typedef void		(*t_ht_entry_cleaner)(void *);

int						ht_init(t_ht *ht, const size_t capacity);

void					*ht_get(const t_ht *ht, const char *key);

/**
 * @brief When the cleaner function is specified, the entry is assumed to be
 * owned by the hashtable. The cleaner function will be called when the entry
 * is freed. Otherwise, user should pass NULL to the cleaner parameter.
*/
const struct s_ht_entry	*ht_set(t_ht *ht, const char *key, const void *value, \
t_ht_entry_cleaner cleaner);

int						ht_resize(t_ht *ht);

void					ht_free(t_ht *ht);

/**
 * @brief hashtable-specific functions
*/

const struct s_ht_entry	*ht_update(t_ht *ht, const char *key, \
const void *value, t_ht_entry_cleaner cleaner);

void					ht_del(t_ht *ht, const char *key);

///////////////////////////////////////////
////////    private interface    //////////
///////////////////////////////////////////

struct s_ht_entry		*ht_get_entry(const t_ht *ht, const char *key);

struct s_ht_entry		*ht_get_empty_entry(const t_ht *ht, const char *key);

/**
 * @brief The hash function used to calculate the index of the storing entry.
*/
size_t					hash(const char *key, size_t capacity);

/**
 * @brief The hash function used to calculate the interval between each probing
 * for that particular entry.
*/
size_t					hash_for_interval(const char *key, size_t capacity);

///////////////////////////////////////////
////////    private interface    //////////
///////////////////////////////////////////

/**
 * @brief The entry of the hashtable. Each entry stores a key, a value, and
 * a cleaner function. When the cleaner is not NULL, it means the entry is
 * owned by the hashtable, and the cleaner function will be run when the
 * entry is freed.
*/
struct s_ht_entry
{
	char				*key;
	void				*value;
	bool				deleted;
	t_ht_entry_cleaner	cleaner;
};

void					ht_entry_init(struct s_ht_entry *entry);

void					ht_entry_delete(struct s_ht_entry *entry);

int						ht_entry_set_key(struct s_ht_entry *entry, \
const char *key);

int						ht_entry_set_value(struct s_ht_entry *entry, \
const void *value, t_ht_entry_cleaner cleaner);

////////////////////////////////////////////
////////      debugp printer      //////////
////////////////////////////////////////////

void					ht_print(t_ht *ht);

#endif