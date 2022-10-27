/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:27:07 by htsang            #+#    #+#             */
/*   Updated: 2022/10/27 12:57:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Locate the first occurance of a string in a longer string. */
char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	char	*str_ptr;
	char	*to_find_ptr;

	if (!str && n == 0)
		return (NULL);
	if (*to_find == 0)
		return ((char *) str);
	while (*str && n)
	{
		str_ptr = (char *) str;
		to_find_ptr = (char *) to_find;
		while (*to_find_ptr && *str_ptr == *to_find_ptr && n--)
		{
			str_ptr++;
			to_find_ptr++;
		}
		if (!*to_find_ptr)
			return ((char *) str);
		n += (str_ptr - str) - 1;
		str++;
	}
	return (NULL);
}
