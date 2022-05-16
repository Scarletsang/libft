/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:46:51 by htsang            #+#    #+#             */
/*   Updated: 2022/05/16 23:57:27 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = (char *) malloc(count * size);
	if (!str)
	{
		return (NULL);
	}
	while (count > 0)
	{
		*str = 0;
		count--;
	}
	return (str);
}
