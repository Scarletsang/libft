/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:23:16 by htsang            #+#    #+#             */
/*   Updated: 2022/10/21 23:41:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t	n;
	char	is_word;

	n = 0;
	is_word = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!is_word)
			{
				n++;
			}
			is_word = 1;
		}
		else
		{
			is_word = 0;
		}
		s++;
	}
	return (n);
}

static char	*ft_deep_free(char **s, size_t size)
{
	while (size)
	{
		free(s[size]);
		size--;
	}
	return (NULL);
}

/* The core logic for copying substring from the original string
to a new array of string.*/
static char	*ft_splitsubstr(char const *s, char c, char **result, size_t count)
{
	char		*substr;
	char const	*ptr;

	ptr = s;
	while (*ptr && *ptr != c)
		ptr++;
	substr = (char *) malloc(ptr - s + 1);
	if (!substr)
		return (ft_deep_free(result, count));
	*result = substr;
	if (!ft_memmove(substr, s, ptr - s))
		return (ft_deep_free(result, count));
	substr[ptr - s] = 0;
	return ((char *) ptr);
}

/* Allocate memory for an array of string that are
splitted from a string s by delimiter c. */
char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	count;
	size_t	i;

	if (!s)
		return (NULL);
	count = ft_count_word(s, c);
	result = (char **) malloc(8 * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s && i < count)
	{
		if (*s != c)
		{
			s = ft_splitsubstr(s, c, result + i, count);
			if (!s)
				return (NULL);
			i++;
		}
		s++;
	}
	result[count] = 0;
	return (result);
}
