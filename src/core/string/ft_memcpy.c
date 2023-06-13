/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:19:44 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 14:55:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/string.h"

/**
** @brief Copy a given size of memory from one byte string to another,
** assuming that NO memory overlapping is possible.
**
** @param dest: destination memory address to be copied to
** @param src:  source memory address to be copied from
** @param size: size of bytes to copy
** @return the destination memory address
*/
void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	void	*original_dest;

	if (dest == 0 && src == 0)
	{
		return (NULL);
	}
	original_dest = dest;
	while (size > 0)
	{
		*(unsigned char *) dest = *(unsigned char *) src;
		dest++;
		src++;
		size--;
	}
	return (original_dest);
}
