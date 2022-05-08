/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:10:25 by htsang            #+#    #+#             */
/*   Updated: 2022/05/08 19:14:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

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
