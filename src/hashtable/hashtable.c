/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:30:47 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/06/30 21:59:14 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/hashtable.h"

/**
 * @details Hashtable is implemented using a vector of entries, this function
 * is a t_ft_vector_item_copier function to copy an entry into another entry.
*/
static void	ht_setter(struct s_ft_ht_entry *entry, \
struct s_ft_ht_entry *new_entry)
{
	entry->key = new_entry->key;
	entry->value = new_entry->value;
	entry->deleted = new_entry->deleted;
	entry->cleaner = new_entry->cleaner;
}

int	ft_ht_init(t_ft_ht *ht, const size_t capacity)
{
	return (ft_vector_init(ht, sizeof(struct s_ft_ht_entry), capacity, \
		(t_ft_vector_item_copier) ht_setter));
}

void	ft_ht_free(t_ft_ht *ht)
{
	size_t	i;

	i = 0;
	while (i < ht->capacity)
	{
		ft_ht_entry_delete(ft_vector_get(ht, i));
		i++;
	}
	ht->size = 0;
	ft_vector_free(ht);
}
