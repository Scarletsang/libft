/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 22:20:17 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 10:09:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include <float.h>
#include <stdio.h>

struct s_ft_parser_atom	ft_parser_float(struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
	struct s_ft_parser_atom				output;
	struct s_ft_parser_float_payload	payload;
	union u_ft_tobject					is_negative;

	(void) option;
	output = ft_parser_ignore(input, ft_tobject_str("-"));
	is_negative = ft_tobject_bool(ft_parser_atom_is_ok(output));
	payload = (struct s_ft_parser_float_payload){\
		.maximum = DBL_MAX,
		.minumum = -DBL_MAX,
		.number = 0.0,
		.power = 0.1};
	output = ft_parser_atom_chain(output, \
		ft_tobject_ptr(&payload), output.string);
	output = ft_decorator_accumulate(ft_parser_entity(\
		&ft_parser_digit_float, is_negative), output, ft_tobject_empty());
	if (!output.is_valid)
		return (ft_parser_atom_validity_set(input, false));
	output = ft_parser_ignore(output, ft_tobject_str((char *) "."));
	if (output.is_valid)
		output = ft_decorator_accumulate(\
			ft_parser_entity(&ft_parser_digit_float_decimal, is_negative), \
			output, ft_tobject_empty());
	return (ft_parser_atom_chain(output, \
		ft_tobject_float(payload.number), output.string));
}
