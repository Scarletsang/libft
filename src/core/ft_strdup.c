/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:06:49 by htsang            #+#    #+#             */
/*   Updated: 2023/06/12 13:06:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"

/**
** @brief Duplicates a string to a new memory address.
**
** @param str: a NULL-terminated stirng
** @return the new string after duplication from the given string
*/
char	*ft_strdup(const char *str)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(str);
	copy = (char *) malloc(len + 1);
	if (!copy)
	{
		return (NULL);
	}
	ft_strncpy(copy, str, len + 1);
	return (copy);
}
