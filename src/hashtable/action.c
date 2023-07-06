/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:35:00 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/07/07 01:42:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/hashtable.h"
#include "internal/hashtable_internal.h"

/**
 * @brief Get the value of a key from the hash table.
 * @param ht The hash table.
 * @param key The key.
 * @return t_ft_object The value of the key, or NULL if the key is not found.
*/
t_ft_object	ft_ht_get(const t_ft_ht *ht, t_ft_str key)
{
	struct s_ft_ht_entry	*entry;

	entry = ft_ht_get_entry(ht, key);
	if (!entry)
		return ((t_ft_object){NULL, 0});
	return (entry->value);
}

const struct s_ft_ht_entry	*ft_ht_set(t_ft_ht *ht, t_ft_str key, \
t_ft_object value, t_ft_ht_entry_cleaner cleaner)
{
	struct s_ft_ht_entry	*entry;

	entry = ft_ht_get_empty_entry(ht, key);
	if (!entry)
		return (NULL);
	if (ft_ht_entry_set_key(entry, key) || \
		ft_ht_entry_set_value(entry, value, cleaner))
	{
		ft_ht_entry_delete(entry);
		return (NULL);
	}
	ht->size++;
	if (ht->size * 100 / ht->capacity > 70)
	{
		if (ft_ht_resize(ht))
			return (NULL);
		return (ft_ht_get_entry(ht, key));
	}
	return (entry);
}

int	ft_ht_delete(t_ft_ht *ht, t_ft_str key)
{
	struct s_ft_ht_entry	*entry;

	entry = ft_ht_get_entry(ht, key);
	if (!entry)
		return (EXIT_FAILURE);
	ft_ht_entry_delete(entry);
	ht->size--;
	return (EXIT_SUCCESS);
}

const struct s_ft_ht_entry	*ft_ht_update(t_ft_ht *ht, t_ft_str key, \
t_ft_object value, t_ft_ht_entry_cleaner cleaner)
{
	struct s_ft_ht_entry	*entry;

	entry = ft_ht_get_entry(ht, key);
	if (!entry)
		return (ft_ht_set(ht, key, value, cleaner));
	if (ft_ht_entry_set_value(entry, value, cleaner))
		return (NULL);
	return (entry);
}
