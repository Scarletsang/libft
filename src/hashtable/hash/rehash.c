/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rehash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 04:17:16 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/06/12 12:52:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/hashtable.h"

static void	ht_clone(t_ht *dest, t_ht *src)
{
	dest->buffer = src->buffer;
	dest->item_size = src->item_size;
	dest->size = src->size;
	dest->capacity = src->capacity;
	dest->setter = src->setter;
}

static int	ht_import(t_ht *ht, struct s_ht_entry *entry)
{
	struct s_ht_entry	*new_entry;

	new_entry = ht_get_empty_entry(ht, entry->key);
	if (!new_entry)
		return (EXIT_FAILURE);
	ht->setter(new_entry, entry);
	ht->size++;
	return (EXIT_SUCCESS);
}

int	ht_resize(t_ht *ht)
{
	size_t				i;
	t_ht				old_ht;
	struct s_ht_entry	*old_entry;

	ht_clone(&old_ht, ht);
	if (ht_init(ht, ht->capacity * 2))
	{
		ht_clone(ht, &old_ht);
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < old_ht.capacity)
	{
		old_entry = vector_get(&old_ht, i++);
		if (!old_entry->key)
			continue ;
		if (ht_import(ht, old_entry))
		{
			vector_free(ht);
			ht_clone(ht, &old_ht);
			return (EXIT_FAILURE);
		}
	}
	vector_free(&old_ht);
	return (EXIT_SUCCESS);
}
