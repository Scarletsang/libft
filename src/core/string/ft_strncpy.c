/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:05:26 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 14:56:43 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/string.h"

/**
 * @brief A non traditional strncpy, where only one 0 will be
 * written after the copying n chars from a source string.
 * 
 * @param dest: the destination string to write to
 * @param src: the source string to copy from
 * @param n: the maximum length of characters to copt from src
 * @return the destination string
 */
char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
