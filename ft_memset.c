/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:38:45 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 15:08:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** @brief Set a given amount of the same value
** to the given memory address.
**
** @param mem:  the memory address
** @param val:  the int value
** @param size: the amount of byte to write
** @return the original memory address
*/
void	*ft_memset(void *mem, int val, size_t size)
{
	unsigned char	*ptr;

	ptr = mem;
	while (size > 0)
	{
		*ptr = (unsigned char) val;
		ptr++;
		size--;
	}
	return (mem);
}
