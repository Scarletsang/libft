/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:52:50 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/07/06 21:17:18 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/hashtable.h"

size_t	ft_hash(t_ft_str key, size_t capacity)
{
	unsigned long	hash;

	hash = 0;
	while (key.size > 0)
	{
		hash += ((char *) key.content)[key.size - 1];
		key.size--;
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

size_t	ft_hash_for_interval(t_ft_str key, size_t capacity)
{
	size_t	hash;
	size_t	interval;
	size_t	max_interval;

	hash = 0;
	while (key.size > 0)
	{
		hash += ((char *) key.content)[key.size - 1];
		key.size--;
	}
	max_interval = capacity * 7 / 10;
	interval = max_interval - (hash % max_interval);
	while (!is_coprime(capacity, interval))
	{
		interval = (interval + 1) % max_interval;
	}
	return (interval);
}
