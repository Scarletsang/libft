/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:46:51 by htsang            #+#    #+#             */
/*   Updated: 2022/10/18 19:24:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/* Allocate memory for a count amount of size byte.
If either of the argument is 0, Null pointer is returned. */
void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count == 0 || size == 0)
	{
		return (NULL);
	}
	str = malloc(count * size);
	if (str == 0)
	{
		return (NULL);
	}
	ft_bzero(str, count * size);
	return ((void *) str);
}
