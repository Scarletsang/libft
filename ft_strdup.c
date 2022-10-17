/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:06:49 by htsang            #+#    #+#             */
/*   Updated: 2022/10/17 17:17:26 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*tmp;

	tmp = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (tmp);
}

char	*ft_strdup(const char *str)
{
	char	*copy;

	copy = (char *) malloc(ft_strlen(str) + 1);
	if (!copy)
	{
		return (NULL);
	}
	ft_strcpy(copy, str);
	return (copy);
}
