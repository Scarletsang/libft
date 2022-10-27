/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:46:51 by htsang            #+#    #+#             */
/*   Updated: 2022/10/27 12:59:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocate memory for a count amount of size byte.
If either of the argument is 0, Null pointer is returned. 
SIZE_MAX / size < count ensures multiplication
won't cause overflow in the malloc. */
void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (size && SIZE_MAX / size < count)
		return (NULL);
	str = malloc(count * size);
	if (str == 0)
	{
		return (NULL);
	}
	ft_bzero(str, count * size);
	return ((void *) str);
}
