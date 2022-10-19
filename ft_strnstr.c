/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:27:07 by htsang            #+#    #+#             */
/*   Updated: 2022/10/19 18:33:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/* Locate the first occurance of a string in a longer string.
Logic: if the comparision fails, it reset the counter j, 
the result pointer. */
char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	int		j;
	char	*p;

	j = 0;
	p = NULL;
	if (*to_find == 0)
		return ((char *) str);
	while (str[j] && to_find[j] && n)
	{
		n--;
		if (str[j] == to_find[j])
		{
			if (p == NULL)
				p = (char *) str;
			j++;
			continue ;
		}
		n += j;
		str++;
		p = NULL;
		j = 0;
	}
	if (to_find[j] == 0)
		return (p);
	return (NULL);
}