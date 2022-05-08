/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:14:05 by htsang            #+#    #+#             */
/*   Updated: 2022/05/08 19:14:43 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

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
	if (c == 0)
		return ((char *) str);
	return (match);
}
