/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:21:34 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 15:10:00 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** @brief set a given amount of 0 to a memory address.
**
** @param mem:  the memory address
** @param size: the amount
*/
void	ft_bzero(void *mem, size_t size)
{
	ft_memset(mem, 0, size);
	return ;
}
