/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:35:00 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/06/13 13:25:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/hashtable.h"

const struct s_ft_ht_entry	*ft_ht_set(t_ft_ht *ht, const char *key, \
const void *value, t_ft_ht_entry_cleaner cleaner)
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

void	ft_ht_delete(t_ft_ht *ht, const char *key)
{
	struct s_ft_ht_entry	*entry;

	entry = ft_ht_get_entry(ht, key);
	if (!entry)
		return ;
	ft_ht_entry_delete(entry);
	ht->size--;
}

const struct s_ft_ht_entry	*ft_ht_update(t_ft_ht *ht, const char *key, \
const void *value, t_ft_ht_entry_cleaner cleaner)
{
	struct s_ft_ht_entry	*entry;

	entry = ft_ht_get_entry(ht, key);
	if (!entry)
		return (ft_ht_set(ht, key, value, cleaner));
	if (ft_ht_entry_set_value(entry, value, cleaner))
		return (NULL);
	return (entry);
}
