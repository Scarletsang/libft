/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decorator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:48:21 by htsang            #+#    #+#             */
/*   Updated: 2023/08/02 23:00:26 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include "LIBFT/vector.h"

struct s_ft_parser_entity	ft_parser_optional(t_ft_parser_curried curried, \
struct s_ft_parser_entity input)
{
	struct s_ft_parser_entity	result;

	result = curried.parser(input, curried.option);
	if (result.is_valid)
		return (result);
	else
		return (input);
}

struct s_ft_parser_entity	ft_parser_accumulate(t_ft_parser_curried curried, \
struct s_ft_parser_entity input)
{
	struct s_ft_parser_entity	result;

	result = curried.parser(input, curried.option);
	if (!result.is_valid)
		return (ft_parser_entity_validity_set(input, true));
	while (!ft_parser_entity_is_end(result))
	{
		input = result;
		result = curried.parser(input, curried.option);
		if (!result.is_valid)
			return (ft_parser_entity_validity_set(input, true));
	}
	return (ft_parser_entity_validity_set(result, true));
}

static struct s_ft_parser_entity	ft_parser_to_vector(\
t_ft_parser_curried curried, struct s_ft_parser_entities *entities, \
t_ft_str input)
{
	return (curried.parser(\
		ft_parser_entity(\
			ft_parser_tobject_ptr(\
				ft_vector_get(&entities->payloads, entities->payloads.size)), \
			input), \
		curried.option));
}

struct s_ft_parser_entities	ft_parser_some(t_ft_parser_curried curried, \
struct s_ft_parser_entities entities)
{
	struct s_ft_parser_entity	result;

	if (entities.payloads.size >= entities.payloads.capacity)
	{
		if (ft_vector_resize(&entities.payloads))
			return (ft_parser_entities_empty());
	}
	result = ft_parser_to_vector(curried, &entities, entities.input);
	while (ft_parser_entity_is_ok(result))
	{
		entities.payloads.size++;
		if (entities.payloads.size >= entities.payloads.capacity)
		{
			if (ft_vector_resize(&entities.payloads))
				return (ft_parser_entities_empty());
		}
		result = ft_parser_to_vector(curried, &entities, result.input);
	}
	entities.input = result.input;
	return (entities);
}
