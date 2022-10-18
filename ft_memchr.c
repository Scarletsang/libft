/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:23:11 by htsang            #+#    #+#             */
/*   Updated: 2022/10/18 11:37:40 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/* Finds the first occurance of a char in an array,
values are interpreted as a unsigned char during comparison. */
void	*ft_memchr(const void *str, int c, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *) str == (unsigned char) c)
		{
			return ((void *) str);
		}
		str++;
		n--;
	}
	return (NULL);
}
