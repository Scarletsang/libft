/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:23:11 by htsang            #+#    #+#             */
/*   Updated: 2022/05/16 23:41:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*char_str;

	char_str = (unsigned char *) str;
	while (n > 0)
	{
		if (*char_str == (unsigned char) c)
		{
			return (char_str);
		}
		char_str++;
		n--;
	}
	return (NULL);
}
