/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:50:45 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/06/12 12:52:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/hashtable.h"

void	ht_entry_init(struct s_ht_entry *entry)
{
	entry->key = NULL;
	entry->value = NULL;
	entry->cleaner = NULL;
	entry->deleted = false;
}

void	ht_entry_delete(struct s_ht_entry *entry)
{
	if (entry->key)
		free(entry->key);
	if (entry->cleaner && entry->value)
	{
		entry->cleaner(entry->value);
		if (entry->cleaner != free)
			free(entry->value);
	}
	entry->key = NULL;
	entry->value = NULL;
	entry->cleaner = NULL;
	entry->deleted = true;
}

/**
 * @details When setting the key of an entry, the given key will be be copied
 * to a new allocated memory using strdup.
*/
int	ht_entry_set_key(struct s_ht_entry *entry, const char *key)
{
	entry->deleted = false;
	entry->key = ft_strdup(key);
	if (!entry->key)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ht_entry_set_value(struct s_ht_entry *entry, const void *value, \
t_ht_entry_cleaner cleaner)
{
	if (entry->cleaner && entry->value)
		entry->cleaner(entry->value);
	if (value && cleaner)
	{
		entry->value = ft_strdup(value);
		if (!entry->value)
			return (EXIT_FAILURE);
		entry->cleaner = cleaner;
	}
	else
	{
		entry->value = (void *) value;
		entry->cleaner = NULL;
	}
	return (EXIT_SUCCESS);
}
