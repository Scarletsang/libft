/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:06:23 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 14:56:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/string.h"

/**
** @brief Safe copy of the source string to the destination 
** string. It only copies up to a maximum amount of char.
**
** @param dest: the destination memory address to copy to.
** @param src:  a NULL-terminated string to be copied from.
** @param max_len: the maximum length of char to be copied.
** @return the length of the destination string after copying.
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t max_len)
{
	size_t	src_size;

	src_size = ft_strlen(src);
	if (max_len == 0)
	{
		return (src_size);
	}
	while (*src && max_len > 1)
	{
		*dest = *src;
		dest++;
		src++;
		max_len--;
	}
	*dest = 0;
	return (src_size);
}
