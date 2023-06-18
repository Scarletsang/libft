/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:09:57 by htsang            #+#    #+#             */
/*   Updated: 2023/06/18 00:36:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/string.h"
#include "LIBFT/slice.h"

char	*ft_string_slice_to_cstring(t_ft_string_slice slice)
{
	char	*cstring;

	if (!slice.content || !slice.size)
		return (NULL);
	cstring = malloc(slice.size + 1);
	if (!cstring)
		return (NULL);
	ft_memcpy(cstring, slice.content, slice.size);
	cstring[slice.size] = '\0';
	return (cstring);
}

char	*ft_string_slice_content(t_ft_string_slice *slice)
{
	return (slice->content);
}
