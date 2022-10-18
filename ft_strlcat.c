/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:34:51 by htsang            #+#    #+#             */
/*   Updated: 2022/10/18 13:09:34 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Concatenate src after dest.
size of the array after concatenation is specified.
Concatenation will not happen if not enough space.ß

Returns the length of the result array,
or if there is not enough space to concatenate,
the expected length of the result array is returned. */
size_t	ft_strlcat(char *dest, const char *src, size_t max_size)
{
	size_t	dest_size;
	size_t	src_size;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (max_size <= dest_size)
	{
		return (max_size + src_size);
	}
	max_size = max_size - dest_size - 1;
	dest = dest + dest_size;
	while (*src && max_size > 0)
	{
		*dest = *src;
		dest++;
		src++;
		max_size--;
	}
	*dest = 0;
	return (dest_size + src_size);
}
