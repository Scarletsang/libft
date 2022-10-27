/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:09:49 by htsang            #+#    #+#             */
/*   Updated: 2022/10/27 12:58:31 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Calculates the difference of the first different char in an array,
valeus are interpreted in unsigned char during comparison. */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
	{
		return (0);
	}
	while (*(unsigned char *) s1 == *(unsigned char *) s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
