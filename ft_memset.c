/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:38:45 by htsang            #+#    #+#             */
/*   Updated: 2022/10/27 13:25:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Fill an array of n size with the same char. */
void	*ft_memset(void *str, int c, size_t n)
{
	while (n > 0)
	{
		*((unsigned char *) str) = (unsigned char) c;
		str++;
		n--;
	}
	return (str);
}
