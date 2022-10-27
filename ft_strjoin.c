/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:11:00 by htsang            #+#    #+#             */
/*   Updated: 2022/10/27 12:57:33 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates memory for a string after joining s1 before s2. */
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
	if (!ptr \
	|| !ft_memmove((void *) ptr, (void const *) s1, s1_len) \
	|| !ft_memmove((void *)(ptr + s1_len), (void const *) s2, s2_len))
	{
		return (NULL);
	}
	*(ptr + s1_len + s2_len) = 0;
	return (ptr);
}
