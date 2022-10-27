/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:19:44 by htsang            #+#    #+#             */
/*   Updated: 2022/10/27 12:58:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copy memory from src to dest, assuming that no overlapping is possible. */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*original_dest;

	if (dest == 0 && src == 0)
	{
		return (NULL);
	}
	original_dest = dest;
	while (n > 0)
	{
		*(unsigned char *) dest = *(unsigned char *) src;
		dest++;
		src++;
		n--;
	}
	return (original_dest);
}
