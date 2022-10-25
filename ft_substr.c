/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:40:48 by htsang            #+#    #+#             */
/*   Updated: 2022/10/25 22:27:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/* Allocates memory for a substring in a longer string.
The substring starts at an index with a given length. */
char	*ft_substr(char const *s, unsigned int start, size_t max_size)
{
	char	*ptr;
	size_t	possible_size;

	if (!s)
		return (NULL);
	while (*s && start)
	{
		s++;
		start--;
	}
	possible_size = 0;
	while (s[possible_size])
		possible_size++;
	if (max_size > possible_size)
		max_size = possible_size;
	ptr = (char *) malloc(max_size + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, max_size + 1);
	return (ptr);
}
