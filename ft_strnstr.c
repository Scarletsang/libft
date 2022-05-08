/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:27:07 by htsang            #+#    #+#             */
/*   Updated: 2022/05/08 19:46:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	int		j;
	char	*p;

	j = 0;
	p = 0;
	if (*to_find == 0)
		return ((char *) str);
	while (*(str + j) && to_find[j] && n)
	{
		if (*(str + j) == to_find[j])
		{
			if (p == 0)
				p = (char *) str;
			n--;
			j++;
			continue ;
		}
		str++;
		n = n + j - 1;
		p = 0;
		j = 0;
	}
	if (to_find[j] == 0)
		return (p);
	return (NULL);
}
