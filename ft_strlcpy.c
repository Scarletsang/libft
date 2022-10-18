/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:06:23 by htsang            #+#    #+#             */
/*   Updated: 2022/10/18 13:29:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copy array from src to dest up to the max size.
Copy will not happen if there is not enough space.*/
size_t	ft_strlcpy(char *dest, const char *src, size_t max_size)
{
	size_t	src_size;

	src_size = ft_strlen(src);
	if (dest == 0 || max_size == 0)
	{
		return (src_size);
	}
	while (*src && max_size > 1)
	{
		*dest = *src;
		dest++;
		src++;
		max_size--;
	}
	*dest = 0;
	return (src_size);
}
