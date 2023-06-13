/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:40:48 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 15:17:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/string.h"

/**
** @brief Cut a substring out of a given string by its starting index
** and length. Th substring is stored in a new memory address. The
** original string is left untouched.
**
** @param str:     a NULL-terminated string to cut the string from.
** @paarm start:   the starting index to cut from the string
** @param max_len: the maximum length to cut from the string
** @return the newly created substring
*/
char	*ft_substr(char const *str, unsigned int start, size_t max_len)
{
	char	*ptr;
	size_t	possible_size;

	if (!str)
		return (NULL);
	while (*str && start)
	{
		str++;
		start--;
	}
	possible_size = ft_strlen(str);
	if (max_len + start > possible_size)
		max_len = possible_size;
	ptr = (char *) malloc(max_len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str, max_len + 1);
	return (ptr);
}
