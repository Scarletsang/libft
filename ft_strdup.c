/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:06:49 by htsang            #+#    #+#             */
/*   Updated: 2022/05/08 22:19:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*copy;

	copy = (char *) malloc(ft_strlen(str));
	if (!copy)
	{
		return (NULL);
	}
	ft_strcpy(copy, str);
	return (copy);
}
