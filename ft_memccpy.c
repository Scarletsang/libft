/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:27:03 by htsang            #+#    #+#             */
/*   Updated: 2022/05/15 17:40:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*dest_str;
	char	*src_str;

	dest_str = (char *) dest;
	src_str = (char *) src;
	while (n > 0)
	{
		*dest_str = *src_str;
		if (*src_str == (char) c)
		{
			return ((void *)++dest_str);
		}
		dest_str++;
		src_str++;
		n--;
	}
	return (NULL);
}
