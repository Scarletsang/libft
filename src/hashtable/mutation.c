/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:35:00 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/06/12 12:52:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/hashtable.h"

const struct s_ht_entry	*ht_set(t_ht *ht, const char *key, const void *value, \
t_ht_entry_cleaner cleaner)
{
	struct s_ht_entry	*entry;

	entry = ht_get_empty_entry(ht, key);
	if (!entry)
		return (NULL);
	if (ht_entry_set_key(entry, key) || \
		ht_entry_set_value(entry, value, cleaner))
	{
		ht_entry_delete(entry);
		return (NULL);
	}
	ht->size++;
	if (ht->size * 100 / ht->capacity > 70)
	{
		if (ht_resize(ht))
			return (NULL);
		return (ht_get_entry(ht, key));
	}
	return (entry);
}

void	ht_del(t_ht *ht, const char *key)
{
	struct s_ht_entry	*entry;

	entry = ht_get_entry(ht, key);
	if (!entry)
		return ;
	ht_entry_delete(entry);
	ht->size--;
}

const struct s_ht_entry	*ht_update(t_ht *ht, const char *key, \
const void *value, t_ht_entry_cleaner cleaner)
{
	struct s_ht_entry	*entry;

	entry = ht_get_entry(ht, key);
	if (!entry)
		return (ht_set(ht, key, value, cleaner));
	if (ht_entry_set_value(entry, value, cleaner))
		return (NULL);
	return (entry);
}
