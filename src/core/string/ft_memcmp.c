/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:09:49 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 14:55:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/string.h"

/**
** @brief Compare the first different byte found between two byte strings.
** Both byte strings are assumed to have the size of the third argument.
**
** @param m1: 1st byte string, interpreted as unsigned char during comparison.
** @param m2: 2nd byte string, interpreted as unsigned char during comparison.
** @param size: the size of both byte string
** @return 0 if both byte strings are identical in value,
** otherwise return the difference of the different byte, m1 - m2.
*/
int	ft_memcmp(const void *m1, const void *m2, size_t size)
{
	if (size == 0)
	{
		return (0);
	}
	while (*(unsigned char *) m1 == *(unsigned char *) m2 && size > 1)
	{
		m1++;
		m2++;
		size--;
	}
	return (*(unsigned char *) m1 - *(unsigned char *) m2);
}
