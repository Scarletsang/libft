/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decorator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:48:21 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 09:20:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include "LIBFT/vector.h"

struct s_ft_parser_atom	ft_decorator_optional(struct s_ft_parser_entity entity, \
struct s_ft_parser_atom input, union u_ft_tobject option)
{
	struct s_ft_parser_atom		result;
	size_t						traces_size;

	(void) option;
	if (input.error_traces)
		traces_size = input.error_traces->traces.size;
	result = ft_parser_entity_evaluate(&entity, input);
	if (result.is_valid)
	{
		if (input.error_traces)
			input.error_traces->traces.size = traces_size;
		return (result);
	}
	else
		return (ft_parser_atom_validity_set(input, true));
}

struct s_ft_parser_atom	ft_decorator_accumulate(\
struct s_ft_parser_entity entity, struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
	struct s_ft_parser_atom	result;

	(void) option;
	result = ft_parser_entity_evaluate(&entity, input);
	if (!result.is_valid)
		return (ft_parser_atom_validity_set(input, false));
	while (!ft_parser_atom_is_end(result))
	{
		input = result;
		result = ft_parser_entity_evaluate(&entity, input);
		if (!result.is_valid)
			return (ft_parser_atom_validity_set(input, true));
	}
	return (ft_parser_atom_validity_set(result, true));
}

static struct s_ft_parser_atom	ft_parser_to_vector(\
struct s_ft_parser_entity *entity, struct s_ft_parser_atom input)
{
	return (ft_parser_entity_evaluate(entity, \
		ft_parser_atom_chain(\
			input, \
			ft_tobject_ptr(\
				ft_vector_get(input.payload.as_vector, \
					input.payload.as_vector->size)), \
			input.string)));
}

struct s_ft_parser_atom	ft_decorator_some(\
struct s_ft_parser_entity entity, struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
	struct s_ft_parser_atom	result;

	(void) option;
	if (input.payload.as_vector->size >= \
		input.payload.as_vector->capacity)
	{
		if (ft_vector_resize(input.payload.as_vector))
			return (ft_parser_atom_unchain(input));
	}
	result = ft_parser_to_vector(&entity, input);
	while (ft_parser_atom_is_ok(result))
	{
		result.payload.as_vector->size++;
		if (result.payload.as_vector->size >= \
			result.payload.as_vector->capacity)
		{
			if (ft_vector_resize(result.payload.as_vector))
				return (ft_parser_atom_unchain(input));
		}
		result = ft_parser_to_vector(&entity, result);
	}
	input.string = result.string;
	return (ft_parser_atom_validity_set(input, true));
}

struct s_ft_parser_atom	ft_decorator_value_as_ptr(\
struct s_ft_parser_entity entity, \
struct s_ft_parser_atom input, union u_ft_tobject type)
{
	struct s_ft_parser_atom	result;

	result = ft_parser_entity_evaluate(&entity, input);
	if (!result.is_valid)
		return (ft_parser_atom_validity_set(input, false));
	else if (type.as_int == FT_TOBJECT_BOOL)
		*(bool *) input.payload.as_ptr = result.payload.as_bool;
	else if (type.as_int == FT_TOBJECT_CHAR)
		*(char *) input.payload.as_ptr = result.payload.as_char;
	else if (type.as_int == FT_TOBJECT_INT)
		*(int *) input.payload.as_ptr = result.payload.as_int;
	else if (type.as_int == FT_TOBJECT_UINT)
		*(unsigned int *) input.payload.as_ptr = result.payload.as_uint;
	else if (type.as_int == FT_TOBJECT_SIZE)
		*(size_t *) input.payload.as_ptr = result.payload.as_size;
	else if (type.as_int == FT_TOBJECT_FLOAT)
		*(double *) input.payload.as_ptr = result.payload.as_float;
	return (ft_parser_atom_chain(input, input.payload, result.string));
}
