/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:09:49 by htsang            #+#    #+#             */
/*   Updated: 2022/10/27 17:44:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Compare the first different byte found between two byte strings.
**
** @param m1: 1st byte string, interpreted as unsigned char during comparison.
** @param m2: 2nd byte string, interpreted as unsigned char during comparison.
** @param max_size: the maximum size of byte string to compare
** @return 0 if both byte strings are identical in value,
** negative numbers if m1 < m2, positive numbers if m1 > m2.
*/
int	ft_memcmp(const void *m1, const void *m2, size_t max_size)
{
	if (max_size == 0)
	{
		return (0);
	}
	while (*(unsigned char *) m1 == *(unsigned char *) m2 && max_size > 1)
	{
		m1++;
		m2++;
		max_size--;
	}
	return (*(unsigned char *) m1 - *(unsigned char *) m2);
}
