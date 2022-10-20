/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:23:16 by htsang            #+#    #+#             */
/*   Updated: 2022/10/20 20:41:30 by htsang           ###   ########.fr       */
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
		// printf("n: %zu\nis_word: %d\ns: %s\n\n", n, is_word, s);
	}
	return (n);
}

static char **ft_deep_free(char **s, size_t size)
{
	while (size)
	{
		free(s[size]);
		size--;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	**result_ptr;
	char	*substr;
	char const	*ptr;

	result = (char **) malloc(sizeof(char *) * ft_count_word(s, c) + 1);
	if (!result)
	{
		return (NULL);
	}
	result_ptr = result;
	while (*s)
	{
		if (*s != c)
		{
			ptr = s;
			while (*ptr && *ptr != c)
			{
				ptr++;
			}
			substr = (char *) malloc(ptr - s + 1);
			if (!substr)
			{
				return (ft_deep_free(result, result_ptr - result));
			}
			if (!ft_memmove(substr, s, ptr - s))
			{
				return (NULL);
			}
			*result_ptr = substr;
			result_ptr++;
			s = ptr;
		}
		s++;
	}
	*result_ptr = 0;
	return (result);
}
