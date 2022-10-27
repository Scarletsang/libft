/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:30:46 by htsang            #+#    #+#             */
/*   Updated: 2022/10/27 13:30:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* Copy memory from src to dest, 
memory overlap is POSSIBLE.
Comparing the dest and src pointer address,
to determine whether to copy chars from the beginning or the end. */
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
