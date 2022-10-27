/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:10:25 by htsang            #+#    #+#             */
/*   Updated: 2022/10/27 12:57:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Finds the first given char in an array,
a pointer to that char is returned. */
char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char) c)
		{
			return ((char *) str);
		}
		str++;
	}
	if (c == 0)
	{
		return ((char *) str);
	}
	return (NULL);
}
