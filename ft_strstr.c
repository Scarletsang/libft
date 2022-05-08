/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:36:37 by htsang            #+#    #+#             */
/*   Updated: 2022/05/08 17:59:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *str, const char *to_find)
{
	int		j;
	char	*p;

	j = 0;
	p = 0;
	if (*to_find == 0)
		return ((char *) str);
	while (*(str + j) && to_find[j])
	{
		if (*(str + j) == to_find[j])
		{
			if (p == 0)
				p = (char *) str;
			j++;
			continue ;
		}
		str++;
		p = 0;
		j = 0;
	}
	if (to_find[j] == 0)
		return (p);
	return (NULL);
}
