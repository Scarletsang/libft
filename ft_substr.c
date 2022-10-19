/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:40:48 by htsang            #+#    #+#             */
/*   Updated: 2022/10/19 18:23:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/* Allocates memory for a substring in a longer string.
The substring starts at an index with a given length. */
char	*ft_substr(char const *s, unsigned int start, size_t max_size)
{
	char	*ptr;

	if (!s)
	{
		return (NULL);
	}
	ptr = (char *) malloc(max_size + 1);
	if (!ptr)
	{
		return (NULL);
	}
	while (*s && start)
	{
		s++;
		start--;
	}
	ft_strlcpy(ptr, s, max_size + 1);
	return (ptr);
}
