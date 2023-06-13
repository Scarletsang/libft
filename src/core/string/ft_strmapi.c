/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:54:14 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 15:18:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/string.h"

/**
** @brief Map a function over a string, and creates a new string
** from it. The given string will not be changed at all.
**
** @param str: a NULL-terminated string to be mapped over
** @param f(index,char):   the function to be applied on every char,
** it takes 2 arguments: the char and its index in the string.
** @return the new string
*/
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	if (!str || !f)
	{
		return (NULL);
	}
	result = (char *) malloc(ft_strlen(str) + 1);
	if (!result)
	{
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		result[i] = f(i, str[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
