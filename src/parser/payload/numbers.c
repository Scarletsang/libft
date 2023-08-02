/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 01:41:25 by htsang            #+#    #+#             */
/*   Updated: 2023/08/02 01:42:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

union u_ft_parser_payload	ft_parser_payload_int(int i)
{
	return ((union u_ft_parser_payload) {.as_int = i});
}

union u_ft_parser_payload	ft_parser_payload_uint(unsigned int uint)
{
	return ((union u_ft_parser_payload) {.as_uint = uint});
}

union u_ft_parser_payload	ft_parser_payload_size(size_t size)
{
	return ((union u_ft_parser_payload) {.as_size = size});
}

union u_ft_parser_payload	ft_parser_payload_float(float f)
{
	return ((union u_ft_parser_payload) {.as_float = f});
}

union u_ft_parser_payload	ft_parser_payload_double(double d)
{
	return ((union u_ft_parser_payload) {.as_double = d});
}
