/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:19:44 by htsang            #+#    #+#             */
/*   Updated: 2022/05/16 22:25:39 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_str;
	char	*src_str;

	if (dest == 0 && src == 0)
	{
		return (NULL);
	}
	dest_str = (char *) dest;
	src_str = (char *) src;
	while (n > 0)
	{
		*dest_str = *src_str;
		dest_str++;
		src_str++;
		n--;
	}
	return (dest);
}
