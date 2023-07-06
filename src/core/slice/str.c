/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:09:57 by htsang            #+#    #+#             */
/*   Updated: 2023/07/06 22:40:02 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "LIBFT/string.h"
#include "LIBFT/slice.h"

t_ft_str	ft_str_slice(const char *cstring, size_t from, size_t to)
{
	if (to < from)
		return ((t_ft_str){(void *)(cstring + to), from - to});
	else
		return ((t_ft_str){(void *)(cstring + from), to - from});
}

t_ft_str	ft_str_from_cstring(const char *cstring)
{
	if (!cstring)
		return ((t_ft_str){NULL, 0});
	return ((t_ft_str){(char *) cstring, ft_strlen(cstring)});
}

char	*ft_str_to_cstring(t_ft_str str)
{
	char	*cstring;

	if (!str.content || !str.size)
		return (NULL);
	cstring = malloc(str.size + 1);
	if (!cstring)
		return (NULL);
	ft_memcpy(cstring, str.content, str.size);
	cstring[str.size] = '\0';
	return (cstring);
}

char	*ft_str_as_ptr(t_ft_str *str)
{
	return (str->content);
}

ssize_t	ft_str_print(t_ft_str str, int fd)
{
	if (!str.content)
		return (0);
	return (write(fd, str.content, str.size));
}
