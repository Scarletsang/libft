/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:23:11 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 14:55:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/string.h"

/**
** @brief Locate the first occurance of a value in a byte string.
**
** @param mem:  the memory address
** @param val:  the value to look for, it is interpreted as an
** unsigned char during comparasion.
** @param max_size: the maximum size of byte to look for the value.
*/
void	*ft_memchr(const void *mem, int val, size_t max_size)
{
	while (max_size > 0)
	{
		if (*(unsigned char *) mem == (unsigned char) val)
		{
			return ((void *) mem);
		}
		mem++;
		max_size--;
	}
	return (NULL);
}
