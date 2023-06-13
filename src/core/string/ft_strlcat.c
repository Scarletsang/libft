/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:34:51 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 14:56:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/string.h"

/** 
** @brief Safe concatenate of the source string after the
** destination string. Length of the string after concatenation
** (including the NULL-terminator) must be specified to ensure
** safe concatenation. Concatenation WILL NOT happen if the
** destination memory address does not have enough space to store
** the entire string after concatenation.
**
** @param dest: a string to concatenated after.
** @param src:  a NULL-terminated string to be copied to dest.
** @param max_len: the maximum length of the destination string after
** concatenation (including the NULL-terminator).
** @return the length of the result array, the expected length of 
** the result array is returned if there is not enough space to
** concatenate.
*/
size_t	ft_strlcat(char *dest, const char *src, size_t max_len)
{
	size_t	dest_size;
	size_t	src_size;

	src_size = ft_strlen(src);
	if (!dest && max_len == 0)
	{
		return (max_len + src_size);
	}
	dest_size = ft_strlen(dest);
	if (max_len <= dest_size)
	{
		return (max_len + src_size);
	}
	max_len = max_len - dest_size - 1;
	dest = dest + dest_size;
	while (*src && max_len > 0)
	{
		*dest = *src;
		dest++;
		src++;
		max_len--;
	}
	*dest = 0;
	return (dest_size + src_size);
}
