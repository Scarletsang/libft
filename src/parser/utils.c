/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:42:03 by htsang            #+#    #+#             */
/*   Updated: 2023/08/02 13:42:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

t_ft_str	ft_parser_advance(t_ft_str input, size_t len)
{
	if (len > input.size)
		return (ft_slice_empty());
	return ((t_ft_str){input.content + len, input.size - len});
}

char	*ft_parser_peek(t_ft_str input, size_t index)
{
	if (index >= input.size)
		return (NULL);
	return ((char *) input.content + index);
}
