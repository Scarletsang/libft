/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:38:45 by htsang            #+#    #+#             */
/*   Updated: 2022/10/27 15:23:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Set a given amount of the same value
** to any given memory address.
**
** @param mem:  the memory address
** @param val:  the int value
** @param size: the amount of byte to write
** @return the original memory address
*/
void	*ft_memset(void *mem, int val, size_t size)
{
	while (size > 0)
	{
		*((unsigned char *) mem) = (unsigned char) val;
		mem++;
		size--;
	}
	return (mem);
}
