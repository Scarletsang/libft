/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:30:46 by htsang            #+#    #+#             */
/*   Updated: 2022/05/15 17:45:33 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char		*dest_str;
	const char	*src_str;

	dest_str = (char *) dest;
	src_str = (const char *) src;
	if (dest < src)
	{
		while (size > 0)
		{
			*dest_str = *src_str;
			dest_str++;
			src_str++;
			size--;
		}
	}
	else if (dest > src)
	{
		while (size > 0)
		{
			dest_str[size - 1] = src_str[size - 1];
			size--;
		}
	}
	return (dest);
}
