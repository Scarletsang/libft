/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 01:38:36 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/07/07 01:37:42 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/hashtable.h"
#include <stdio.h>

void	ft_ht_print(t_ft_ht *ht)
{
	size_t					i;
	struct s_ft_ht_entry	*entry;

	i = 0;
	while (i < ht->capacity)
	{
		entry = ft_vector_get(ht, i);
		if (entry->key)
			printf("%s: %s", entry->key, (char *) entry->value.content);
		else
			printf("EMPTY");
		if (entry->deleted)
			printf(" (deleted)\n");
		else
			printf("\n");
		i++;
	}
	printf("\n");
}
