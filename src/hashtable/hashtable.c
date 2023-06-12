/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:30:47 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/06/12 12:52:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/hashtable.h"

/**
 * @details Hashtable is implemented using a vector of entries, this function
 * is a t_vector_setter function to copy an entry into another entry.
*/
static void	ht_setter(struct s_ht_entry *entry, struct s_ht_entry *new_entry)
{
	entry->key = new_entry->key;
	entry->value = new_entry->value;
	entry->deleted = new_entry->deleted;
	entry->cleaner = new_entry->cleaner;
}

int	ht_init(t_ht *ht, const size_t capacity)
{
	return (vector_init(ht, sizeof(struct s_ht_entry), capacity, \
		(t_vector_setter) ht_setter));
}

void	ht_free(t_ht *ht)
{
	size_t	i;

	i = 0;
	while ((ht->size > 0) && (i < ht->capacity))
	{
		ht_entry_delete(vector_get(ht, i));
		ht->size--;
		i++;
	}
	vector_free(ht);
}
