/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decorator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:48:21 by htsang            #+#    #+#             */
/*   Updated: 2023/08/09 00:10:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include "LIBFT/vector.h"

struct s_ft_parser_atom	ft_parser_optional(struct s_ft_parser_entity entity, \
struct s_ft_parser_atom input)
{
	struct s_ft_parser_atom	result;

	result = ft_parser_entity_evaluate(&entity, input);
	if (result.is_valid)
		return (result);
	else
		return (input);
}

struct s_ft_parser_atom	ft_parser_accumulate(\
struct s_ft_parser_entity entity, struct s_ft_parser_atom input)
{
	struct s_ft_parser_atom	result;

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
		ft_parser_atom(\
			ft_tobject_ptr(\
				ft_vector_get(input.payload.as_vector, \
					input.payload.as_vector->size)), \
			input.string)));
}

struct s_ft_parser_atom	ft_parser_some(\
struct s_ft_parser_entity entity, struct s_ft_parser_atom input)
{
	struct s_ft_parser_atom	result;

	if (input.payload.as_vector->size >= \
		input.payload.as_vector->capacity)
	{
		if (ft_vector_resize(input.payload.as_vector))
			return (ft_parser_atom_empty(input.string, false));
	}
	result = ft_parser_to_vector(&entity, input);
	while (ft_parser_atom_is_ok(result))
	{
		result.payload.as_vector->size++;
		if (result.payload.as_vector->size >= \
			result.payload.as_vector->capacity)
		{
			if (ft_vector_resize(result.payload.as_vector))
				return (ft_parser_atom_empty(result.string, false));
		}
		result = ft_parser_to_vector(&entity, result);
	}
	input.string = result.string;
	return (input);
}
