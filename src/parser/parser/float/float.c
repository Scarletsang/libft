/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 22:20:17 by htsang            #+#    #+#             */
/*   Updated: 2023/08/09 01:05:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include <float.h>

struct s_ft_parser_atom	ft_parser_float(struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
	struct s_ft_parser_atom				output;
	struct s_ft_parser_float_payload	payload;
	union u_ft_tobject					is_negative;

	(void) option;
	output = ft_parser_ignore(input, ft_tobject_str((char *) "-"));
	is_negative = ft_tobject_bool(ft_parser_atom_is_ok(output));
	payload = (struct s_ft_parser_float_payload){\
		.maximum = DBL_MAX,
		.minumum = DBL_MIN,
		.number = 0.0,
		.power = 1.0
	};
	output = ft_parser_atom(ft_tobject_ptr(&payload), output.string);
	output = ft_parser_accumulate(\
		ft_parser_entity(&ft_parser_digit_float, is_negative), output);
	if (!ft_parser_atom_is_ok(output))
		return (ft_parser_atom_validity_set(input, false));
	output = ft_parser_ignore(output, ft_tobject_str((char *) "."));
	if (ft_parser_atom_is_ok(output))
		output = ft_parser_accumulate(\
			ft_parser_entity(&ft_parser_digit_float_decimal, is_negative), \
			output);
	return (ft_parser_atom(ft_tobject_float(payload.number), output.string));
}
