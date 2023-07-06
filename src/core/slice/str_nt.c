/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_nt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:37:41 by htsang            #+#    #+#             */
/*   Updated: 2023/07/06 22:43:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/string.h"
#include "LIBFT/slice.h"

t_ft_str_nt	ft_str_nt_from_cstring(const char *cstring)
{
	if (!cstring)
		return ((t_ft_str){NULL, 0});
	return ((t_ft_str){(char *) cstring, ft_strlen(cstring) + 1});
}

char	*ft_str_nt_to_cstring(t_ft_str_nt str_nt)
{
	char	*cstring;

	if (!str_nt.content || !str_nt.size)
		return (NULL);
	cstring = malloc(str_nt.size);
	if (!cstring)
		return (NULL);
	ft_memcpy(cstring, str_nt.content, str_nt.size - 1);
	cstring[str_nt.size - 1] = '\0';
	return (cstring);
}
