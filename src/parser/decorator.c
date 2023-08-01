/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decorator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:48:21 by htsang            #+#    #+#             */
/*   Updated: 2023/08/01 21:39:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include "LIBFT/vector.h"
#include <stdio.h>

struct s_ft_parser_entity	ft_parser_optional(\
t_ft_parser parser, struct s_ft_parser_entity input, void *option)
{
	struct s_ft_parser_entity	result;

	result = parser(input, option);
	if (result.payload)
		return (result);
	else
		return (input);
}

static struct s_ft_parser_entity	ft_parser_to_vector(t_ft_parser parser, \
struct s_ft_parser_entities *entities, void *option, t_ft_str input)
{
	return (parser(\
		ft_parser_entity(\
			ft_vector_get(&entities->payloads, entities->payloads.size), \
			input, false), \
		option));
}

struct s_ft_parser_entities	ft_parser_some(\
t_ft_parser parser, struct s_ft_parser_entities entities, void *option)
{
	struct s_ft_parser_entity	result;

	if (entities.payloads.size >= entities.payloads.capacity)
	{
		if (ft_vector_resize(&entities.payloads))
			return (ft_parser_entities_empty());
	}
	result = ft_parser_to_vector(parser, &entities, option, entities.input);
	while (ft_parser_entity_is_ok(result))
	{
		entities.payloads.size++;
		if (entities.payloads.size >= entities.payloads.capacity)
		{
			if (ft_vector_resize(&entities.payloads))
				return (ft_parser_entities_empty());
		}
		result = ft_parser_to_vector(parser, &entities, option, result.input);
	}
	entities.input = result.input;
	return (entities);
}
