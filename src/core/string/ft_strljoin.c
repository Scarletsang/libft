/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strljoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:08:11 by htsang            #+#    #+#             */
/*   Updated: 2023/06/19 19:17:32 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/string.h"

/**
 * @brief Append a string of length to the end of the dest string.
 * Dest can be null, then it will create a copy of a source string
 * with a given maximum length.
 * 
 * @param dest: the dest NULL-terminated string to append to,
 * this memory address will be freed.
 * @param src: the NULL-terminated string to be appended.
 * @param len: the maximum length of characters to append from src
 * @return a new dest string after concatenation.
 */
char	*ft_strljoin(char *dest, char const *src, size_t len)
{
	size_t	s1_len;
	char	*new_str;

	if (dest)
	{
		s1_len = ft_strlen(dest);
		new_str = (char *) malloc(s1_len + len + 1);
		if (!new_str)
			return (free(dest), NULL);
		ft_strncpy(new_str, dest, s1_len);
		ft_strncpy(new_str + s1_len, src, len);
		free(dest);
	}
	else
	{
		new_str = (char *) malloc(len + 1);
		if (!new_str)
			return (NULL);
		ft_strncpy(new_str, src, len);
	}
	return (new_str);
}
