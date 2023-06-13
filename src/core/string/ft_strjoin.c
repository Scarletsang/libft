/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:11:00 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 15:17:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/string.h"

/**
** @brief Join two strings into a new memory. The second string
** is concatenated after the first string. It is equivalence
** to the "concat" function in other programming languages.
**
** @param s1: the 1st NULL-terminated string
** @param s2: the 2nd NULL-terminated string
** @return a new memory address storing the string after
** concatenation of the 2 original strings. NULL is returned if
** malloc fails.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *) malloc(s1_len + s2_len + 1);
	if (!ptr)
	{
		return (NULL);
	}
	ft_memmove((void *) ptr, (void const *) s1, s1_len);
	ft_memmove((void *)(ptr + s1_len), (void const *) s2, s2_len);
	*(ptr + s1_len + s2_len) = 0;
	return (ptr);
}
