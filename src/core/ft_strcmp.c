/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:26:44 by htsang            #+#    #+#             */
/*   Updated: 2023/06/12 12:41:06 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"

/**
** @brief Compare the first different byte found between two strings.
** Comparision stops when a string terminated.
**
** @param s1: 1st string.
** @param s2: 2nd string.
** @return 0 if both strings are identical in value,
** negative numbers if m1 < m2, positive numbers if m1 > m2.
*/
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
