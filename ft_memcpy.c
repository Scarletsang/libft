/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:19:44 by htsang            #+#    #+#             */
/*   Updated: 2022/05/16 19:43:44 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_str;
	char	*src_str;

	if (dest == 0 && src == 0)
	{
		return (dest);
	}
	dest_str = (char *) dest;
	src_str = (char *) src;
	while (*src_str && n > 0)
	{
		*dest_str = *src_str;
		dest_str++;
		src_str++;
		n--;
	}
	*dest_str = 0;
	return (dest);
}
