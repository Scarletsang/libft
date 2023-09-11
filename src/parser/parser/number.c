/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:09:40 by htsang            #+#    #+#             */
/*   Updated: 2023/09/08 09:16:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

struct s_ft_parser_atom	ft_parser_int(struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
	bool	is_negative;

	(void) option;
	input = ft_parser_char(input, ft_tobject_str((char *) "-"));
	is_negative = ft_parser_atom_is_ok(input);
	input = ft_parser_atom_payload_set(input, ft_tobject_int(0));
	input.is_valid = true;
	return (ft_decorator_accumulate(\
		ft_parser_entity(&ft_parser_digit_int, \
			ft_tobject_bool(is_negative)), input, ft_tobject_empty()));
}

struct s_ft_parser_atom	ft_parser_uint(struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
	(void) option;
	input = ft_parser_atom_chain(input, ft_tobject_int(0), input.string);
	return (ft_decorator_accumulate(\
		ft_parser_entity(&ft_parser_digit_uint, ft_tobject_empty()), input, \
		ft_tobject_empty()));
}

struct s_ft_parser_atom	ft_parser_size(struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
	(void) option;
	input = ft_parser_atom_chain(input, ft_tobject_int(0), input.string);
	return (ft_decorator_accumulate(\
		ft_parser_entity(&ft_parser_digit_size, ft_tobject_empty()), input, \
		ft_tobject_empty()));
}
