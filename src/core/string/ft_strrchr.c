/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:14:05 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 14:56:50 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/string.h"

/**
** @brief Locate the last given char in a given string.
**
** @param str: a NULL-terminated string
** @param c:   the value to find in the string, it is interpreted
** as char during search.
** @return the memory address of the value in the string
*/
char	*ft_strrchr(const char *str, int c)
{
	char	*match;

	match = NULL;
	while (*str)
	{
		if (*str == (char) c)
		{
			match = (char *) str;
		}
		str++;
	}
	if ((char) c == 0)
	{
		return ((char *) str);
	}
	return (match);
}
