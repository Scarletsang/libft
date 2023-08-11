/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:31:42 by htsang            #+#    #+#             */
/*   Updated: 2023/08/09 01:03:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include "LIBFT/ctype.h"

struct s_ft_parser_atom	ft_parser_digit_float_decimal(\
struct s_ft_parser_atom input, union u_ft_tobject is_negative)
{
	char								*c;
	struct s_ft_parser_float_payload	*payload;

	c = ft_parser_peek(input.string, 0);
	payload = input.payload.as_ptr;
	if (!c || !ft_isdigit(*c))
		return (ft_parser_atom_empty(input.string, false));
	else if (is_negative.as_bool)
	{
		if (payload->number < (payload->minumum + \
			((*c - '0') * payload->power)))
			return (ft_parser_atom_empty(input.string, false));
		payload->number -= ((*c - '0') * payload->power);
	}
	else
	{
		if (payload->number > (payload->maximum - \
			((*c - '0') * payload->power)))
			return (ft_parser_atom_empty(input.string, false));
		payload->number += ((*c - '0') * payload->power);
	}
	return (ft_parser_atom(input.payload, ft_parser_advance(input.string, 1)));
}

struct s_ft_parser_atom	ft_parser_digit_float(\
struct s_ft_parser_atom input, union u_ft_tobject is_negative)
{
	char								*c;
	struct s_ft_parser_float_payload	*payload;

	c = ft_parser_peek(input.string, 0);
	payload = input.payload.as_ptr;
	if (!c || !ft_isdigit(*c))
		return (ft_parser_atom_empty(input.string, false));
	else if (is_negative.as_bool)
	{
		if (payload->number < (payload->minumum + (*c - '0')) / 10.f)
			return (ft_parser_atom_empty(input.string, false));
		payload->number = payload->number * 10.f - (*c - '0');
	}
	else
	{
		if (payload->number > (payload->maximum - (*c - '0')) / 10.f)
			return (ft_parser_atom_empty(input.string, false));
		payload->number = payload->number * 10.f + (*c - '0');
	}
	return (ft_parser_atom(input.payload, ft_parser_advance(input.string, 1)));
}