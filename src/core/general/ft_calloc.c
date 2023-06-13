/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:46:51 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 14:54:22 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/general.h"

/**
** @brief Allocate memory for a given amount of byte
** with a certain size. The memory is initialized with
** all bytes filled with 0.
** 
** @details SIZE_MAX / size < count ensures multiplication
** won't cause overflow in the malloc. Size is also
** checked because it will cause the division to fail
** when size is 0.
**
** @param count: amount of memory chunk
** @param size:  size of the memory chunk
** @return the memory address with the corresponding size,
** null when malloc fails.
*/
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
