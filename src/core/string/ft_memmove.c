/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:30:46 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 14:55:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/string.h"

static void	*ft_memcpy_from_last(void *dest, const void *src, size_t size)
{
	void	*original_dest;

	original_dest = dest;
	while (size > 0)
	{
		*(unsigned char *)(dest + size - 1) = \
		*(unsigned char *)(src + size - 1);
		size--;
	}
	return (original_dest);
}

/**
** @brief Copy a given size of memory from one byte string to
** another, assuming that memory overlapping IS possible.
** 
** @details Comparing the dest and src pointer to determine
** whether to copy bytes from the beginning or the end.
**
** @param dest: destination memory address to be copied to
** @param src:  source memory address to be copied from
** @param size: size of bytes to copy
** @return the destination memory address
*/
void	*ft_memmove(void *dest, const void *src, size_t size)
{
	if (!dest && !src)
	{
		return (NULL);
	}
	if (dest < src)
	{
		return (ft_memcpy(dest, src, size));
	}
	else if (dest > src)
	{
		return (ft_memcpy_from_last(dest, src, size));
	}
	return (dest);
}
