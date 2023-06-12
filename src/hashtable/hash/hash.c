/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:52:50 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/06/12 12:52:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/hashtable.h"

size_t	hash(const char *key, size_t capacity)
{
	unsigned long	hash;
	size_t			i;

	hash = 0;
	i = 0;
	while (key[i])
	{
		hash += key[i];
		i++;
	}
	return (hash % capacity);
}

static bool	is_coprime(size_t a, size_t b)
{
	size_t	tmp;

	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return (a == 1);
}

size_t	hash_for_interval(const char *key, size_t capacity)
{
	size_t	hash;
	size_t	interval;
	size_t	max_interval;

	hash = 0;
	while (*key)
	{
		hash += *key;
		key++;
	}
	max_interval = capacity * 7 / 10;
	interval = max_interval - (hash % max_interval);
	while (!is_coprime(capacity, interval))
	{
		interval = (interval + 1) % max_interval;
	}
	return (interval);
}
