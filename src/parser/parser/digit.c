/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:31:50 by htsang            #+#    #+#             */
/*   Updated: 2023/08/04 14:46:06 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include "LIBFT/ctype.h"
#include <limits.h>

struct s_ft_parser_atom	ft_parser_digit_int(struct s_ft_parser_atom input, \
union u_ft_tobject is_negative)
{
	char	*c;

	c = ft_parser_peek(input.string, 0);
	if (!c || !ft_isdigit(*c))
		return (ft_parser_atom_empty(input.string, false));
	else if (is_negative.as_bool)
	{
		if (input.payload.as_int < (INT_MIN + (*c - '0')) / 10)
			return (ft_parser_atom_empty(input.string, false));
		input.payload.as_int = input.payload.as_int * 10 - (*c - '0');
	}
	else
	{
		if (input.payload.as_int > (INT_MAX - (*c - '0')) / 10)
			return (ft_parser_atom_empty(input.string, false));
		input.payload.as_int = input.payload.as_int * 10 + (*c - '0');
	}
	return (ft_parser_atom(input.payload, ft_parser_advance(input.string, 1)));
}

struct s_ft_parser_atom	ft_parser_digit_uint(struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
	char	*c;

	(void) option;
	c = ft_parser_peek(input.string, 0);
	if (!c || !ft_isdigit(*c))
		return (ft_parser_atom_empty(input.string, false));
	else
	{
		if (input.payload.as_uint > (UINT_MAX - (*c - '0')) / 10)
			return (ft_parser_atom_empty(input.string, false));
		input.payload.as_uint = input.payload.as_uint * 10 + (*c - '0');
	}
	return (ft_parser_atom(input.payload, ft_parser_advance(input.string, 1)));
}

struct s_ft_parser_atom	ft_parser_digit_size(struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
	char	*c;

	(void) option;
	c = ft_parser_peek(input.string, 0);
	if (!c || !ft_isdigit(*c))
		return (ft_parser_atom_empty(input.string, false));
	else
	{
		if (input.payload.as_size > (SIZE_MAX - (*c - '0')) / 10)
			return (ft_parser_atom_empty(input.string, false));
		input.payload.as_size = input.payload.as_size * 10 + (*c - '0');
	}
	return (ft_parser_atom(input.payload, ft_parser_advance(input.string, 1)));
}

struct s_ft_parser_atom	ft_parser_digit_float(\
struct s_ft_parser_atom input, union u_ft_tobject is_negative)
{
	char	*c;

	c = ft_parser_peek(input.string, 0);
	if (!c || !ft_isdigit(*c))
		return (ft_parser_atom_empty(input.string, false));
	else if (is_negative.as_bool)
		input.payload.as_float = input.payload.as_float * 10 - (*c - '0');
	else
		input.payload.as_float = input.payload.as_float * 10 + (*c - '0');
	return (ft_parser_atom(input.payload, ft_parser_advance(input.string, 1)));
}

struct s_ft_parser_atom	ft_parser_digit_double(\
struct s_ft_parser_atom input, union u_ft_tobject is_negative)
{
	char	*c;

	c = ft_parser_peek(input.string, 0);
	if (!c || !ft_isdigit(*c))
		return (ft_parser_atom_empty(input.string, false));
	else if (is_negative.as_bool)
		input.payload.as_double = input.payload.as_double * 10 - (*c - '0');
	else
		input.payload.as_double = input.payload.as_double * 10 + (*c - '0');
	return (ft_parser_atom(input.payload, ft_parser_advance(input.string, 1)));
}
