/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rehash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 04:17:16 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/07/06 15:21:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/hashtable.h"
#include "internal/hashtable_internal.h"

static void	ht_clone(t_ft_ht *dest, t_ft_ht *src)
{
	dest->buffer = src->buffer;
	dest->item_size = src->item_size;
	dest->size = src->size;
	dest->capacity = src->capacity;
	dest->copier = src->copier;
}

static int	ht_import(t_ft_ht *ht, struct s_ft_ht_entry *entry)
{
	struct s_ft_ht_entry	*new_entry;

	new_entry = ft_ht_get_empty_entry(ht, ft_str_from_cstring(entry->key));
	if (!new_entry)
		return (EXIT_FAILURE);
	ht->copier(new_entry, entry);
	ht->size++;
	return (EXIT_SUCCESS);
}

int	ft_ht_resize(t_ft_ht *ht)
{
	size_t					i;
	t_ft_ht					old_ht;
	struct s_ft_ht_entry	*old_entry;

	ht_clone(&old_ht, ht);
	if (ft_ht_init(ht, ht->capacity * 2))
	{
		ht_clone(ht, &old_ht);
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < old_ht.capacity)
	{
		old_entry = ft_vector_get(&old_ht, i++);
		if (!old_entry->key)
			continue ;
		if (ht_import(ht, old_entry))
		{
			ft_vector_free(ht);
			ht_clone(ht, &old_ht);
			return (EXIT_FAILURE);
		}
	}
	ft_vector_free(&old_ht);
	return (EXIT_SUCCESS);
}
