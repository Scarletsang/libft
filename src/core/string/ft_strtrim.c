/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:34:45 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 15:18:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/string.h"

static int	ft_charinset(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

/**
** @brief Trim the start and end of a string by removing chars that
** is in the given set. The trimmed string is stored in a new memory
** address. The original string is not touched at all.
**
** @param str: a NULL-terminated string to be trimmed.
** @param set: a char array represents a set of chars that needs
** to be trimmed.
** @return the new trimmed string
*/
char	*ft_strtrim(char const *str, char const *set)
{
	char	*ptr;
	char	*end;

	if (!str || !set)
		return (NULL);
	while (ft_charinset(*str, set))
		str++;
	end = (char *) str;
	while (*end)
		end++;
	if (str == end)
		return (ft_strdup(""));
	end--;
	while (ft_charinset(*end, set))
		end--;
	ptr = (char *) malloc(end - str + 2);
	if (!ptr)
		return (NULL);
	ft_memmove(ptr, str, end - str + 1);
	ptr[end - str + 1] = 0;
	return (ptr);
}
