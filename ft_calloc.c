/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:46:51 by htsang            #+#    #+#             */
/*   Updated: 2022/05/17 00:45:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	total;

	total = count * size;
	str = (char *) malloc(total);
	if (str == 0)
	{
		return (NULL);
	}
	ft_bzero(str, total);
	return ((void *) str);
}
