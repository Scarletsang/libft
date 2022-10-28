/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:23:16 by htsang            #+#    #+#             */
/*   Updated: 2022/10/28 16:09:43 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Counts the amount of splitted string seperated by 
** delimiter c.
*/
static size_t	ft_count_word(char const *str, char c)
{
	size_t	n;
	char	is_word;

	n = 0;
	is_word = 0;
	while (*str)
	{
		if (*str != c)
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
		str++;
	}
	return (n);
}

/*
** @brief free pointers contained in an array
*/
static char	*ft_deep_free(char **result, size_t count)
{
	while (count)
	{
		free(result[count]);
		count--;
	}
	free(result);
	return (NULL);
}

/* 
** @brief The core logic for copying substring from the original string
to a new array of string.
** 
** @param str: the string to be splitted
** @param c: the delimiter
** @param result: the array that contains splitted string
** @param count: size of the result array
** @return pointer pointing to the end of substring on str
*/
static char	*ft_splitstr(char const *str, char c, char **result, size_t count)
{
	char		*substr;
	char const	*end;

	end = str;
	while (*end && *end != c)
		end++;
	substr = (char *) malloc((end - str + 1) * sizeof(char));
	if (!substr)
		return (ft_deep_free(result, count));
	*result = substr;
	if (!ft_memmove(substr, str, end - str))
		return (ft_deep_free(result, count));
	substr[end - str] = 0;
	return ((char *) end);
}

/* 
** @brief Allocate memory for an array of string that are
** splitted from a string str by delimiter c.
** 
** @param str: the string to be splitted
** @param c: delimiter
** @return the splitted string in an array
*/
char	**ft_split(char const *str, char c)
{
	char	**result;
	size_t	count;
	size_t	i;

	if (!str)
		return (NULL);
	count = ft_count_word(str, c);
	result = (char **) malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*str && i < count)
	{
		if (*str != c)
		{
			str = ft_splitstr(str, c, result + i, count) - 1;
			if (!str)
				return (NULL);
			i++;
		}
		str++;
	}
	result[i] = 0;
	return (result);
}
