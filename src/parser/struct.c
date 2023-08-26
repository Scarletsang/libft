/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 03:24:58 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 14:54:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

struct s_ft_parser_struct	ft_parser_struct_init(void **fields, size_t amount)
{
	return ((struct s_ft_parser_struct){
		.fields = ft_slice(fields, amount),
		.current = 0
	});
}

void	*ft_parser_struct_current(struct s_ft_parser_struct *parser)
{
	return (((void **) parser->fields.content)[parser->current]);
}

struct s_ft_parser_atom	ft_decorator_struct_field(\
struct s_ft_parser_entity entity, struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
	struct s_ft_parser_atom		result;
	struct s_ft_parser_struct	*parser;

	(void) option;
	parser = input.payload.as_ptr;
	if (parser->current >= parser->fields.size)
		return (ft_parser_atom_validity_set(input, false));
	result = ft_parser_entity_evaluate(&entity, ft_parser_atom(\
		ft_tobject_ptr(ft_parser_struct_current(parser)), input.string));
	if (!result.is_valid)
		return (ft_parser_atom_validity_set(input, false));
	parser->current++;
	return (ft_parser_atom(input.payload, result.string));
}
