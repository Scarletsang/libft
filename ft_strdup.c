/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:06:49 by htsang            #+#    #+#             */
/*   Updated: 2022/10/27 18:06:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* @brief Simple copy an array from src to dest. Unsafe operation. */
static char	*ft_strcpy(char *dest, const char *src)
{
	char	*tmp;

	tmp = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (tmp);
}

/* 
** @brief Duplicates a string to a new memory address.
**
** @param str: a NULL-terminated stirng
** @return the new string after duplication from the given string
*/
char	*ft_strdup(const char *str)
{
	char	*copy;

	copy = (char *) malloc(ft_strlen(str) + 1);
	if (!copy)
	{
		return (NULL);
	}
	ft_strcpy(copy, str);
	return (copy);
}
