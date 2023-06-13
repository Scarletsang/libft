/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:27:07 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 14:56:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/string.h"

/**
** @brief Locate the first occurance of a string(needle) in
** a longer string(haystack).
**
** @param haystack: a NULL-terminated string to be searched in
** @param needle:   a NULL-terminated string to find in haystack
** @param max_len:  the maximum length to search in the haystack
** @return the pointer to the needle location
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t max_len)
{
	char	*haystack_ptr;
	char	*needle_ptr;

	if (!haystack && max_len == 0)
		return (NULL);
	if (*needle == 0)
		return ((char *) haystack);
	while (*haystack && max_len)
	{
		haystack_ptr = (char *) haystack;
		needle_ptr = (char *) needle;
		while (*needle_ptr && *haystack_ptr == *needle_ptr && max_len--)
		{
			haystack_ptr++;
			needle_ptr++;
		}
		if (!*needle_ptr)
			return ((char *) haystack);
		max_len += (haystack_ptr - haystack) - 1;
		haystack++;
	}
	return (NULL);
}
