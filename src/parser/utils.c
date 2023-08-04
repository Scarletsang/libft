/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:42:03 by htsang            #+#    #+#             */
/*   Updated: 2023/08/04 02:10:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

t_ft_str	ft_parser_advance(t_ft_str string, size_t len)
{
	if ((len > string.size) || (string.size == 1))
		return (ft_slice_empty());
	return ((t_ft_str){string.content + len, string.size - len});
}

char	*ft_parser_peek(t_ft_str string, size_t index)
{
	if (index >= string.size)
		return (NULL);
	return ((char *) string.content + index);
}
