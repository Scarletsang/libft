/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:46:51 by htsang            #+#    #+#             */
/*   Updated: 2022/10/17 17:41:44 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	total;

	if (size == 0)
	{
		return (NULL);
	}
	if ((size_t) -1 / size < count)
	{
		return (NULL);
	}
	total = count * size;
	str = malloc(total);
	if (str == 0)
	{
		return (NULL);
	}
	ft_bzero(str, total);
	return ((void *) str);
}