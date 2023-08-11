/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 02:25:29 by htsang            #+#    #+#             */
/*   Updated: 2023/08/11 22:06:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

struct s_ft_parser_entity	ft_parser_entity(t_ft_parser parser, \
union u_ft_tobject option)
{
	return ((struct s_ft_parser_entity){
		.type = FT_PARSER,
		.construct = {.as_parser = ft_parser_curry(parser, option)}
	});
}

struct s_ft_parser_entity	ft_decorator_entity(\
t_ft_parser_decorator decorator, struct s_ft_parser_entity *entity, \
union u_ft_tobject option)
{
	return ((struct s_ft_parser_entity){
		.type = FT_PARSER_DECORATOR,
		.construct = {
			.as_decorator = ft_decorator_curry(decorator, entity, option)
		}
	});
}

struct s_ft_parser_entity	ft_combinator_entity(\
t_ft_parser_combinator combinator, struct s_ft_parser_entity *entities, \
size_t amount, union u_ft_tobject option)
{
	return ((struct s_ft_parser_entity){
		.type = FT_PARSER_COMBINATOR,
		.construct = {
			.as_combinator = ft_combinator_curry(\
				combinator, entities, amount, option)
		}
	});
}

struct s_ft_parser_atom	ft_parser_entity_evaluate(\
struct s_ft_parser_entity *entity, struct s_ft_parser_atom input)
{
	if (entity->type == FT_PARSER)
		return (ft_parser_evaluate(entity->construct.as_parser, input));
	else if (entity->type == FT_PARSER_DECORATOR)
		return (ft_parser_decorator_evaluate(\
			entity->construct.as_decorator, input));
	else if (entity->type == FT_PARSER_COMBINATOR)
		return (ft_parser_combinator_evaluate(\
			entity->construct.as_combinator, input));
	else
		return (ft_parser_atom_empty(input.string, false));
}
