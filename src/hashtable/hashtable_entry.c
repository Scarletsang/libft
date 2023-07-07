/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_entry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:50:45 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/07/07 04:39:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/hashtable.h"
#include "internal/hashtable_internal.h"

void	ft_ht_entry_init(struct s_ft_ht_entry *entry)
{
	entry->key = NULL;
	entry->value = (t_ft_object){NULL, 0};
	entry->cleaner = NULL;
	entry->deleted = false;
}

void	ft_ht_entry_delete(struct s_ft_ht_entry *entry)
{
	if (entry->key)
		free(entry->key);
	if (entry->cleaner && entry->value.content)
	{
		entry->cleaner(entry->value.content);
		if (entry->cleaner != free)
			free(entry->value.content);
	}
	entry->key = NULL;
	entry->value = (t_ft_object){NULL, 0};
	entry->cleaner = NULL;
	entry->deleted = true;
}

/**
 * @details When setting the key of an entry, the given key will be be copied
 * to a new allocated memory using strdup.
*/
int	ft_ht_entry_set_key(struct s_ft_ht_entry *entry, t_ft_str key)
{
	entry->deleted = false;
	entry->key = ft_str_to_cstring(key);
	if (!entry->key)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_ht_entry_set_value(struct s_ft_ht_entry *entry, t_ft_object value, \
t_ft_ht_entry_cleaner cleaner)
{
	if (entry->cleaner && entry->value.content)
		entry->cleaner(entry->value.content);
	if (value.content && (value.size > 0) && cleaner)
	{
		entry->value.content = malloc(value.size);
		entry->value.size = value.size;
		if (!entry->value.content)
			return (EXIT_FAILURE);
		ft_memmove(entry->value.content, value.content, value.size);
		entry->cleaner = cleaner;
	}
	else
	{
		entry->value = value;
		entry->value.size = value.size;
		entry->cleaner = NULL;
	}
	return (EXIT_SUCCESS);
}
