/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:09:57 by htsang            #+#    #+#             */
/*   Updated: 2023/07/02 12:19:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "LIBFT/string.h"
#include "LIBFT/slice.h"

t_ft_str	ft_str_slice(char *cstring, size_t from, size_t to)
{
	if (to < from)
		return ((t_ft_str) {cstring + to, from - to});
	else
		return ((t_ft_str) {cstring + from, to - from});
}

t_ft_str	ft_str_from_cstring(const char *cstring)
{
	if (!cstring)
		return ((t_ft_str) {NULL, 0});
	return ((t_ft_str) {(char *) cstring, ft_strlen(cstring)});
}

char	*ft_str_to_cstring(t_ft_str slice)
{
	char	*cstring;

	if (!slice.content || !slice.len)
		return (NULL);
	cstring = malloc(slice.len + 1);
	if (!cstring)
		return (NULL);
	ft_memcpy(cstring, slice.content, slice.len);
	cstring[slice.len] = '\0';
	return (cstring);
}

char	*ft_str_as_ptr(t_ft_str *slice)
{
	return (slice->content);
}

ssize_t	ft_str_print(t_ft_str slice, int fd)
{
	if (!slice.content)
		return (0);
	return (write(fd, slice.content, slice.len));
}
