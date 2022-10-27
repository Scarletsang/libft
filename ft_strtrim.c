/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:34:45 by htsang            #+#    #+#             */
/*   Updated: 2022/10/27 13:05:31 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int static	ft_charinset(char c, char const *set)
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

/* Trim start and end chars from an array that is included in a set. */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	char	*end;

	if (!s1 || !set)
		return (NULL);
	while (ft_charinset(*s1, set))
		s1++;
	end = (char *) s1;
	while (*end)
		end++;
	if (s1 == end)
		return ((char *) ft_calloc(1, 1));
	end--;
	while (ft_charinset(*end, set))
		end--;
	ptr = (char *) malloc(end - s1 + 2);
	if (!ptr)
		return (NULL);
	ft_memmove(ptr, s1, end - s1 + 1);
	ptr[end - s1 + 1] = 0;
	return (ptr);
}
