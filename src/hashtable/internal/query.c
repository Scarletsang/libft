/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:43:08 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/07/06 21:18:22 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/hashtable.h"
#include "hashtable_internal.h"

struct s_ft_ht_entry	*ft_ht_get_entry(const t_ft_ht *ht, t_ft_str key)
{
	size_t					index;
	size_t					interval;
	struct s_ft_ht_entry	*entry;

	index = ft_hash(key, ht->capacity);
	entry = ft_vector_get(ht, index);
	if (!(entry->key || entry->deleted))
		return (NULL);
	if (entry->key && ft_strncmp(\
		entry->key, (const char *) key.content, key.size) == 0)
		return (entry);
	interval = ft_hash_for_interval(key, ht->capacity);
	while (entry->key || entry->deleted)
	{
		index = (index + interval) % ht->capacity;
		entry = ft_vector_get(ht, index);
		if (entry->key && (ft_strncmp(\
			entry->key, (const char *) key.content, key.size) == 0))
			return (entry);
	}
	return (NULL);
}

struct s_ft_ht_entry	*ft_ht_get_empty_entry(const t_ft_ht *ht, \
t_ft_str key)
{
	size_t					index;
	size_t					interval;
	struct s_ft_ht_entry	*entry;

	index = ft_hash(key, ht->capacity);
	entry = ft_vector_get(ht, index);
	if (!entry->key)
		return (entry);
	if (ft_strncmp(\
		entry->key, (const char *) key.content, key.size) == 0)
		return (NULL);
	interval = ft_hash_for_interval(key, ht->capacity);
	while (entry->key)
	{
		index = (index + interval) % ht->capacity;
		entry = ft_vector_get(ht, index);
		if (entry->key && (ft_strncmp(\
			entry->key, (const char *) key.content, key.size) == 0))
			return (NULL);
	}
	return (entry);
}
