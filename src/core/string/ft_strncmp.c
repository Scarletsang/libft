/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:26:44 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 14:56:39 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/string.h"

/**
** @brief Compare the first different byte found between two strings.
** Comparision stops when a string terminated.
**
** @param s1: 1st string.
** @param s2: 2nd string.
** @param max_len: the maximum length of bytes to compare
** @return 0 if both strings are identical in value,
** negative numbers if m1 < m2, positive numbers if m1 > m2.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t max_len)
{
	while (*s1 && *s2 && *s1 == *s2 && max_len > 0)
	{
		s1++;
		s2++;
		max_len--;
	}
	if (max_len == 0)
	{
		return (0);
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
